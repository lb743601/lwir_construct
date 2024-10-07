#include "cam_info.h"
#include <QString>
#include <iostream>
#include <string>
InfoDialog::InfoDialog(MainWindow *parent,daheng_camera *camera) :
    QDialog(parent),
    mainWindow(parent) ,
    daheng_cam(camera)
{
    ui.setupUi(this);  // 使用自动生成的 setupUi
}

InfoDialog::~InfoDialog()
{
}
void InfoDialog::on_pushButton_clicked()
{
    QString currentText = ui.lineEdit->text();
    std::string str=currentText.toStdString();
    try {
        double exp_time = std::stod(str);
        daheng_cam->set_exp(exp_time);
        mainWindow->log_print("设置成功");
    } catch (const std::invalid_argument &e) {
        mainWindow->log_print("错误的曝光值");
    } catch (const std::out_of_range &e) {
        mainWindow->log_print("错误的曝光值");
    }
    
    
}