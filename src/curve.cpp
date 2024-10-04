#include "curve.h"
#include <QFileDialog>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <opencv2/opencv.hpp>
#include <hdf5.h>
#include <vector>
#include <iostream>

CurveDialog::CurveDialog(MainWindow *parent) :
    QDialog(parent),
    mainWindow(parent)
{
    ui.setupUi(this);

    // 设置事件过滤器来捕获图像点击
    ui.graphicsView->viewport()->installEventFilter(this);
}

CurveDialog::~CurveDialog()
{
}

// 加载MAT文件并处理
void CurveDialog::loadMatFile(const QString &filePath)
{
    // 打开 HDF5 文件
    hid_t file_id = H5Fopen(filePath.toStdString().c_str(), H5F_ACC_RDONLY, H5P_DEFAULT);
    if (file_id < 0) {
        mainWindow->log_print("无法打开 MAT 文件: " + filePath.toStdString());
        return;
    }

    // 打开数据集（假设数据集名为 "cube"）
    hid_t dataset_id = H5Dopen(file_id, "/cube", H5P_DEFAULT);
    if (dataset_id < 0) {
        mainWindow->log_print("无法打开数据集 'cube'。");
        H5Fclose(file_id);
        return;
    }

    // 获取数据集的维度信息
    hid_t dataspace_id = H5Dget_space(dataset_id);
    hsize_t dims[3];  // 假设数据是3维的：bands, height, width
    H5Sget_simple_extent_dims(dataspace_id, dims, nullptr);
    bands = dims[0];
    size_t height = dims[1];
    size_t width = dims[2];
    std::cout << "读取到的矩阵尺寸: 宽度 = " << width << ", 高度 = " << height << ", 波段数 = " << bands << std::endl;

    // 读取数据到内存
    data.resize(bands * height * width);
    herr_t status = H5Dread(dataset_id, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, data.data());
    if (status < 0) {
        mainWindow->log_print("无法读取数据。");
        H5Sclose(dataspace_id);
        H5Dclose(dataset_id);
        H5Fclose(file_id);
        return;
    }


    // auto [minIt, maxIt] = std::minmax_element(data.begin(), data.end());
    // float dataMinValue = *minIt;
    // float dataMaxValue = *maxIt;
    // std::cout << "数据值范围: 最小值 = " << dataMinValue << ", 最大值 = " << dataMaxValue << std::endl;
    // 生成RGB图像 (选择3个波段，模拟生成 RGB)
    cv::Mat rImage(height, width, CV_32F, data.data() + 3 * width * height);   // 第4个波段
    cv::Mat gImage(height, width, CV_32F, data.data() + 14 * width * height);  // 第15个波段
    cv::Mat bImage(height, width, CV_32F, data.data() + 25 * width * height);  // 第26个波段

    cv::Mat rgbImage;
    std::vector<cv::Mat> channels = {bImage, gImage, rImage};  // BGR顺序
    cv::merge(channels, rgbImage);

    // 图像顺时针旋转90度
    cv::Mat rotatedImage;
    cv::rotate(rgbImage, rotatedImage, cv::ROTATE_90_CLOCKWISE);

    // 归一化RGB图像
    cv::normalize(rotatedImage, rotatedImage, 0, 255, cv::NORM_MINMAX);
    rotatedImage.convertTo(rotatedImage, CV_8U);

    // 将图像显示在QGraphicsView中
    QImage qImage(rotatedImage.data, rotatedImage.cols, rotatedImage.rows, rotatedImage.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(pixmap);
    ui.graphicsView->setScene(scene);

    // 将图像保存到 simulatedRGB
    simulatedRGB = rotatedImage.clone();

    // 清理资源
    H5Sclose(dataspace_id);
    H5Dclose(dataset_id);
    H5Fclose(file_id);
}

// 处理图像点击事件
void CurveDialog::onImageClicked(QMouseEvent *event)
{
    QPointF pt = ui.graphicsView->mapToScene(event->pos());
    int x = static_cast<int>(pt.x());
    int y = static_cast<int>(pt.y());

    // 验证点击点是否在图像范围内
    if (x >= 0 && x < simulatedRGB.cols && y >= 0 && y < simulatedRGB.rows) {
        // 计算点击位置的光谱数据
        std::vector<float> spectrum(bands);
        for (int band = 0; band < bands; ++band) {
            spectrum[band] = data[band * simulatedRGB.rows * simulatedRGB.cols + y * simulatedRGB.cols + x];
        }

        // 将光谱数据添加到绘图小部件，传递像素位置用于图例显示
        ui.widget->addSpectrumData(spectrum, QPoint(x, y));
    }
}

// 按钮点击，加载 MAT 文件
void CurveDialog::on_pushButton_clicked()
{
    QString matFilePath = QFileDialog::getOpenFileName(this, tr("选择 MAT 文件"), "", tr("MAT 文件 (*.mat)"));
    if (!matFilePath.isEmpty()) {
        loadMatFile(matFilePath);  // 加载MAT文件并显示RGB图像
    }
}

void CurveDialog::on_pushButton_2_clicked()
{
    // 清除绘图小部件中的所有光谱曲线
    ui.widget->clearSpectra();
}

bool CurveDialog::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui.graphicsView->viewport() && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        onImageClicked(mouseEvent);  // 调用处理点击事件的函数
        return true;  // 表示事件已经被处理
    }
    return QDialog::eventFilter(watched, event);  // 默认处理其他事件
}
