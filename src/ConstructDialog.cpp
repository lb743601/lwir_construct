#include "ConstructDialog.h"
#include <QFileDialog>
#include <QString>
#include <filesystem> 
#include <iostream>
ConstructDialog::ConstructDialog(MainWindow *parent) :
    QDialog(parent),
    mainWindow(parent) 
{
    ui.setupUi(this);  // 使用自动生成的 setupUi
}

ConstructDialog::~ConstructDialog()
{
}
void ConstructDialog::on_pushButton_3_clicked()
{
    std::string model_path = ui.label->text().toStdString();
    std::string input_image_path = ui.label_2->text().toStdString();
    std::string output_path = "./output";
    if (!std::filesystem::exists(output_path)) {
        std::filesystem::create_directory(output_path);  // 创建 output 文件夹
    }
    std::string command = "python3 /home/jetson/Downloads/mst++/MST-plus-plus-master/predict_code/run.py --pretrained_model_path " + model_path + " --rgb_path " + input_image_path + " --outf " + output_path;
    int result = system(command.c_str());
    if(result==0) mainWindow->log_print("重构成功");
    else mainWindow->log_print("重构失败");

}
void ConstructDialog::on_pushButton_clicked()
{
    // 打开文件选择窗口
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择模型文件"), "", tr("模型文件 (*.model);;所有文件 (*)"));
    
    // 如果用户选择了文件，则将文件路径更新到 label 上
    if (!filePath.isEmpty()) {
        ui.label->setText(filePath);  // 更新 label 显示
    }
}

void ConstructDialog::on_pushButton_2_clicked()
{
    // 打开文件选择窗口
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择输入图像"), "", tr("图像文件 (*.png *.jpg *.jpeg);;所有文件 (*)"));
    // 如果用户选择了文件，则将文件路径更新到 label_2 上
    if (!filePath.isEmpty()) {
        ui.label_2->setText(filePath);  // 更新 label_2 显示
    }
}