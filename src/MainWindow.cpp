#include "MainWindow.h"
#include "ui_main.h" // 生成的UI文件
#include <QTimer>
#include <QImage>
#include <QDir>          // 添加 QDir 头文件
#include <QFileInfo>     // 添加 QFileInfo 头文件
#include <QFileInfoList> 
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <QDateTime>
#include "ConstructDialog.h"
#include "mat2bmp.h"
#include "curve.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    camera("/dev/video0"),
    serialPort(),
    timer(new QTimer(this)),
    constructDialog(nullptr),
    matdialog(nullptr),
    curvedialog(nullptr)
    
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateFrame);
    connect(ui->dir_checkbox,&QCheckBox::stateChanged,this,&MainWindow::set_dir);
    
    dir_flag=0;
    com_flag=0;
    cam_flag=0;
}

MainWindow::~MainWindow() {
    delete ui;
    camera.close();
    //serialPort.unlock();
    serialPort.close();
}

void MainWindow::saveGrayImage(cv::Mat &grayImage) {
    // Step 1: 获取当前时间（精确到秒）
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentTime = currentDateTime.toString("yyyy-MM-dd_hh-mm-ss");

    // Step 2: 创建 data 目录
    QDir dir;
    if (!dir.exists("./data")) {
        dir.mkdir("./data");  // 如果 data 目录不存在，创建它
    }

    // Step 3: 创建以当前时间命名的文件夹
    QString folderPath = "./data/" + currentTime;

    // 如果文件夹不存在，创建它
    if (!dir.exists(folderPath)) {
        dir.mkdir(folderPath);
    }

    // Step 4: 生成文件名，精确到毫秒，确保文件名唯一
    QString currentTimeWithMilliseconds = currentDateTime.toString("yyyy-MM-dd_hh-mm-ss-zzz"); // 精确到毫秒
    QString imagePath = folderPath + "/" + currentTimeWithMilliseconds + ".png";  // 图片文件路径

    // Step 5: 保存图像
    if (cv::imwrite(imagePath.toStdString(), grayImage)) {
        log_print("保存成功");
    } else {
        log_print("保存失败");
    }
}
std::string MainWindow::getCurrentTimeString() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm *tm_now = std::localtime(&now_time);
    
    std::ostringstream oss;
    oss << std::put_time(tm_now, "%Y-%m-%d_%H-%M-%S");  // 格式化为 "YYYY-MM-DD_HH-MM-SS"
    return oss.str();
}
void MainWindow::on_openCameraButton_clicked() {
    
        if(cam_flag==0)
        {
            if(camera.initialize())
            {
                timer->start(30); // 每30毫秒更新一次
                log_print("打开相机成功");
                cam_flag=1;
                ui->openCameraButton->setText("关闭相机");
                ui->camera_status->setText("打开");
            }
            else log_print("打开相机失败");
        }
        else
        {
            timer->stop();
            camera.close();
            cam_flag=0;
            log_print("关闭相机成功");
            ui->openCameraButton->setText("打开相机");
            ui->camera_status->setText("关闭");
        }
        
    
}

void MainWindow::updateFrame() {
    cv::Mat frame = camera.getCurrentFrame();

    if (!frame.empty()) {
        // 将 OpenCV 的灰度图像转换为 QImage
        QImage img = QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_Grayscale8);
       
        // 获取 QLabel 的尺寸
        int labelWidth = ui->camera_image_label->width();
        int labelHeight = ui->camera_image_label->height();
        
        // 保持原始的长宽比缩放图像，同时根据 QLabel 的尺寸居中显示
        QPixmap pixmap = QPixmap::fromImage(img).scaled(labelWidth, labelHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // 计算 QLabel 中的空白区域，并调整 QPixmap 的位置
        int xOffset = (labelWidth - pixmap.width()) / 2;
        int yOffset = (labelHeight - pixmap.height()) / 2;
        ui->camera_image_label->setPixmap(pixmap);
        ui->camera_image_label->setAlignment(Qt::AlignCenter);
        ui->camera_image_label->setContentsMargins(xOffset, yOffset, xOffset, yOffset); // 设置内容边距以居中图像
    } else {
        // 处理帧为空的情况
        std::cerr << "无法获取帧，图像为空" << std::endl;
    }
}


void MainWindow::on_open_com_button_clicked()
{
    if(com_flag==0)
    {   
        QString currentText = ui->comboBox->currentText();
        com_flag=serialPort.initialize(currentText.toStdString());
        if(com_flag==1)
        {
            log_print("打开串口成功");
            ui->com_status->setText("打开");
            ui->open_com_button->setText("关闭串口");
        }
        else log_print("打开串口失败");
        
    }
    else
    {   //serialPort.unlock();
        if(serialPort.close())
           {ui->open_com_button->setText("打开串口");
            ui->com_status->setText("关闭");
            com_flag=0;
            log_print("关闭串口成功");
            }
        else log_print("关闭串口失败");

    }
    // std::string command = "start_pwm(72,200,12800)";
    // serialPort.send(command);
}
void MainWindow::set_dir(int state)
{
    if(com_flag==1)
    {
        if(state==2)
        {
            serialPort.set_dir(0);
            dir_flag=0;
            ui->zhengfan_stauts->setText("正");
            log_print("设置电机旋转方向为正");
        }
        else
        {
           serialPort.set_dir(1);
            dir_flag=1;
            ui->zhengfan_stauts->setText("反");
            log_print("设置电机旋转方向为反"); 
        }
    }
    else log_print("未打开串口");
}
void MainWindow::log_print(std::string log)
{
    ui->info_text_edit->appendPlainText(QString::fromStdString(log));
}

void MainWindow::on_rot_button_clicked()
{
    if(com_flag==1)
    {
        QString currentText = ui->angle_line_edit->text();
        std::string str=currentText.toStdString();
        int pwm_num=0;
        try {
            pwm_num = std::stoi(str);
            serialPort.rot(pwm_num);
            log_print("旋转成功");      
        } catch (const std::invalid_argument &e) {
            log_print("无效的参数"); 
        } catch (const std::out_of_range &e) {
            log_print("数字越界"); 
        }

    }
    else log_print("未打开串口");
}
void MainWindow::on_auto_button_clicked()
{
    if(cam_flag)
    {
        if(com_flag)
        QTimer::singleShot(0, [=]() { captureAndRotate(1); });
        else log_print("未打开串口");
    }
    else log_print("未打开相机");
    

}
void MainWindow::captureAndRotate(int step) {
    cv::Mat frame = camera.getCurrentFrame();
    saveGrayImage(frame);
    
    QTimer::singleShot(200, [=]() {
        if (step < 5) {
            serialPort.rot(72);  // 旋转 72 度
            QTimer::singleShot(1500, [=]() { captureAndRotate(step + 1); });  // 延时 2 秒后拍下一张
        } else {
            //QTimer::singleShot(1000, [=]() { serialPort.rot(72); });
            serialPort.rot(72);  // 延时 1 秒后旋转回原位
        }
    });
}
void MainWindow::on_save_button_clicked()
{
    if(cam_flag==1)
    {
        cv::Mat frame = camera.getCurrentFrame();
        saveGrayImage(frame);
    }
    else log_print("未打开相机");
}
void MainWindow::on_construct_button_clicked()
{
    if (!constructDialog) {
        constructDialog = new ConstructDialog(this);
    }
    constructDialog->exec();  // 以模态对话框方式显示
}
void MainWindow::on_spectral_curve_button_clicked()
{
    if (!curvedialog) {
        curvedialog = new CurveDialog(this);
    }
    curvedialog->exec();
}
void  MainWindow::on_mat2bmp_button_clicked()
{
 if (!matdialog) {
        matdialog = new mat2bmp(this);
    }
    matdialog->exec();
}