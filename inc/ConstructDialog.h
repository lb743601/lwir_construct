#ifndef CONSTRUCTDIALOG_H
#define CONSTRUCTDIALOG_H

#include <QDialog>
#include "ui_construct.h"  // 自动生成的头文件是 ui_construct.h
#include "MainWindow.h" 
class ConstructDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConstructDialog(MainWindow *parent = nullptr);
    
    ~ConstructDialog();
    
private slots:
    void on_pushButton_clicked();
private :
    MainWindow *mainWindow; 
    Ui::Dialog ui;  // 使用 Ui::Dialog
    
};

#endif // CONSTRUCTDIALOG_H
