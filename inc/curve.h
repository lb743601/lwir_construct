#ifndef CURVE_H
#define CURVE_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "ui_curve.h"
#include "MainWindow.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include <QMouseEvent>
#include <QWidget>
#include <QPainter>
#include "SpectralPlotWidget.h"
#include <limits>

class CurveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CurveDialog(MainWindow *parent = nullptr);
    ~CurveDialog();

private slots:
    void on_pushButton_clicked();  // 加载MAT文件
    void on_pushButton_2_clicked();  // 刷新按钮
    void onImageClicked(QMouseEvent *event);  // 捕捉图像点击事件

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    MainWindow *mainWindow;
    Ui::curve_Dialog ui;
    QGraphicsScene *scene;
    int bands;
    std::vector<float> data;  // 保存光谱数据
    cv::Mat simulatedRGB;  // 模拟的RGB图像

    // 加载 MAT 文件并处理成光谱数据
    void loadMatFile(const QString &filePath);
};

#endif // CURVE_H
