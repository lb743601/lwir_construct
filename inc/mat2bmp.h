#ifndef MAT2BMP_H
#define MAT2BMP_H

#include <QDialog>
#include "ui_mat2bmp.h"  // 自动生成的头文件是 ui_construct.h
#include "MainWindow.h" 
class mat2bmp : public QDialog
{
    Q_OBJECT

public:
    explicit mat2bmp(MainWindow *parent = nullptr);
    
    ~mat2bmp();
    
private slots:
    void on_pushButton_clicked();
private :
    void convertMatToBMP(const QString &matFilePath, const QString &outputDir);
    MainWindow *mainWindow; 
    Ui::mat2bmp_Dialog ui;  // 使用 Ui::Dialog
    
};

#endif
