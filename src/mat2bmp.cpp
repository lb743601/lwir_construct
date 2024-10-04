#include "mat2bmp.h"
#include <QFileDialog>
#include <QString>
#include <QDir>
#include <filesystem> 
#include <iostream>
#include <opencv2/opencv.hpp>
#include <hdf5.h>  // 包含 HDF5 库头文件
#include <string>

mat2bmp::mat2bmp(MainWindow *parent) :
    QDialog(parent),
    mainWindow(parent) 
{
    ui.setupUi(this);  // 使用自动生成的 setupUi
}

mat2bmp::~mat2bmp()
{
}

void mat2bmp::on_pushButton_clicked()
{
    // 弹出文件选择窗口，选择 .mat 文件
    QString matFilePath = QFileDialog::getOpenFileName(this, tr("选择 MAT 文件"), "", tr("MAT 文件 (*.mat)"));
    
    if (matFilePath.isEmpty()) {
        mainWindow->log_print("未选择文件。" );
        return;
    }

    // 设置 bmp_output 目录
    QString outputDir = QDir::currentPath() + "/bmp_output";
    
    // 检查 bmp_output 目录是否存在，如果不存在则创建
    if (!std::filesystem::exists(outputDir.toStdString())) {
        std::filesystem::create_directory(outputDir.toStdString());
    }

    // 根据输入的 .mat 文件名，创建一个新文件夹来保存 BMP 输出
    QFileInfo fileInfo(matFilePath);
    QString baseName = fileInfo.completeBaseName();  // 获取不带扩展名的文件名
    QString subDir = outputDir + "/" + baseName;

    // 检查子目录是否存在，如果不存在则创建
    if (!std::filesystem::exists(subDir.toStdString())) {
        std::filesystem::create_directory(subDir.toStdString());
    }

    // 调用函数将 .mat 文件转换为 BMP 图像，并将结果保存到新建的文件夹中
    convertMatToBMP(matFilePath, subDir);
}

void mat2bmp::convertMatToBMP(const QString &matFilePath, const QString &outputDir)
{
    // 打开 HDF5 文件
    hid_t file_id = H5Fopen(matFilePath.toStdString().c_str(), H5F_ACC_RDONLY, H5P_DEFAULT);
    if (file_id < 0) {
        // 将 QString 转换为 std::string
        mainWindow->log_print("无法打开 MAT 文件: " + matFilePath.toStdString());
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
    hsize_t dims[3]; // 假设数据是3维的：height, width, bands
    H5Sget_simple_extent_dims(dataspace_id, dims, nullptr);
    size_t height = dims[1];
    size_t width = dims[2];
    size_t bands = dims[0];
    std::cout << "读取到的矩阵尺寸: 宽度 = " << width << ", 高度 = " << height << ", 波段数 = " << bands << std::endl;

    // 读取数据到内存
    std::vector<float> data(height * width * bands);
    herr_t status = H5Dread(dataset_id, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, data.data());
    if (status < 0) {
        mainWindow->log_print("无法读取数据。");
        H5Sclose(dataspace_id);
        H5Dclose(dataset_id);
        H5Fclose(file_id);
        return;
    }

    // 遍历每个频段，将其转换为 BMP 图像
    for (size_t band = 0; band < bands; ++band) {
        // 创建 OpenCV Mat 并填充数据
        cv::Mat image(height, width, CV_32F);
        for (size_t i = 0; i < height; ++i) {
            for (size_t j = 0; j < width; ++j) {
                image.at<float>(i, j) = data[band * width * height + i * width + j];
            }
        }

        // 顺时针旋转90度
        cv::Mat rotatedImage;
        cv::rotate(image, rotatedImage, cv::ROTATE_90_CLOCKWISE);

        // 获取图像的最小值和最大值
        double minVal, maxVal;
        cv::minMaxLoc(rotatedImage, &minVal, &maxVal);

        // 归一化为 0-255 范围的 8-bit 图像
        cv::Mat normalizedImage;
        rotatedImage.convertTo(normalizedImage, CV_8U, 255.0 / (maxVal - minVal), -minVal * 255.0 / (maxVal - minVal));

        // 保存为 BMP 文件
        QString outputPath = outputDir + QString("/band_%1.bmp").arg(band);
        cv::imwrite(outputPath.toStdString(), normalizedImage);
    }

    // 关闭 HDF5 资源
    H5Sclose(dataspace_id);
    H5Dclose(dataset_id);
    H5Fclose(file_id);
    mainWindow->log_print("MAT 文件转换为 BMP 成功。");
}
