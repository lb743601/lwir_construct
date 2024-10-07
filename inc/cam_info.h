#ifndef CAM_INFO_H
#define CAM_INFO_H
#include "ui_camera_info.h"  // 自动生成的头文件是
#include "MainWindow.h"
#include "daheng_camera.h"
class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(MainWindow *parent = nullptr,daheng_camera *camera = nullptr);
    
    ~InfoDialog();
    
private slots:
    void on_pushButton_clicked();
    
private :
    MainWindow *mainWindow; 
    Ui::info_dialog ui;  // 使用 Ui::Dialog
    daheng_camera *daheng_cam;
};

#endif