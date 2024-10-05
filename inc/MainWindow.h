#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "Camera.h"
#include "daheng_camera.h"
#include "SerialPort.h"
class ConstructDialog;
class mat2bmp;
class CurveDialog;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT // 这个宏是必须的

public:
    void log_print(std::string log);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openCameraButton_clicked();
    void updateFrame(); // 用于更新相机画面
    void on_rot_button_clicked();
    void on_auto_button_clicked();
    void on_save_button_clicked();
    void on_construct_button_clicked();
    void on_open_com_button_clicked();
    void on_spectral_curve_button_clicked();
    void on_mat2bmp_button_clicked();
    void set_dir(int state);
    
    std::string getCurrentTimeString() ;
    void saveGrayImage(cv::Mat& grayImage) ;
    void captureAndRotate(int step) ;
private:
    Ui::MainWindow *ui;
    Camera camera;
    //daheng_camera daheng_cam;
    SerialPort serialPort;
    QTimer *timer;
    int dir_flag;
    int com_flag;
    int cam_flag;
    ConstructDialog *constructDialog; 
    mat2bmp *matdialog;
    CurveDialog *curvedialog;
};

#endif // MAINWINDOW_H
