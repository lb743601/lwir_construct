#include "ConstructDialog.h"
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
void ConstructDialog::on_pushButton_clicked()
{
    std::string model_path = "/path/to/model";
    std::string input_image_path = "/path/to/input_image";
    std::string output_path = "/path/to/output";
    std::string activate_command="conda activate water";
    int result = system(activate_command.c_str());
    // 创建完整的命令字符串
    std::string command = "python3 /home/jetson/Downloads/mst++/MST-plus-plus-master/predict_code/run.py " + model_path + " " + input_image_path + " " + output_path;
    result = system(command.c_str());
}