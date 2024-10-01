/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *camera_info_button;
    QPushButton *construct_button;
    QPushButton *spectral_curve_button;
    QFrame *line;
    QLabel *camera_image_label;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QPlainTextEdit *info_text_edit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *openCameraButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *open_com_button;
    QComboBox *comboBox;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *rot_button;
    QCheckBox *dir_checkbox;
    QPushButton *save_button;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *angle_label;
    QLineEdit *angle_line_edit;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *auto_button;
    QComboBox *auto_box;
    QFrame *line_2;
    QFrame *line_8;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *camera_label;
    QLabel *camera_status;
    QHBoxLayout *horizontalLayout_8;
    QLabel *com_label;
    QLabel *com_status;
    QHBoxLayout *horizontalLayout_7;
    QLabel *zhengfan_label;
    QLabel *zhengfan_stauts;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(671, 450);
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 391, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        camera_info_button = new QPushButton(verticalLayoutWidget);
        camera_info_button->setObjectName(QString::fromUtf8("camera_info_button"));

        horizontalLayout->addWidget(camera_info_button);

        construct_button = new QPushButton(verticalLayoutWidget);
        construct_button->setObjectName(QString::fromUtf8("construct_button"));

        horizontalLayout->addWidget(construct_button);

        spectral_curve_button = new QPushButton(verticalLayoutWidget);
        spectral_curve_button->setObjectName(QString::fromUtf8("spectral_curve_button"));

        horizontalLayout->addWidget(spectral_curve_button);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        camera_image_label = new QLabel(centralwidget);
        camera_image_label->setObjectName(QString::fromUtf8("camera_image_label"));
        camera_image_label->setGeometry(QRect(10, 90, 375, 300));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 90, 400, 5));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(2);
        line_3->setFrameShape(QFrame::HLine);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(10, 390, 400, 5));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(2);
        line_4->setFrameShape(QFrame::HLine);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(400, 90, 20, 301));
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setLineWidth(2);
        line_5->setFrameShape(QFrame::VLine);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(0, 90, 20, 301));
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setLineWidth(2);
        line_6->setFrameShape(QFrame::VLine);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(430, 0, 20, 421));
        line_7->setFrameShadow(QFrame::Raised);
        line_7->setLineWidth(2);
        line_7->setFrameShape(QFrame::VLine);
        info_text_edit = new QPlainTextEdit(centralwidget);
        info_text_edit->setObjectName(QString::fromUtf8("info_text_edit"));
        info_text_edit->setGeometry(QRect(450, 320, 211, 91));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(470, 20, 171, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        openCameraButton = new QPushButton(horizontalLayoutWidget);
        openCameraButton->setObjectName(QString::fromUtf8("openCameraButton"));

        horizontalLayout_2->addWidget(openCameraButton);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(470, 50, 196, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        open_com_button = new QPushButton(horizontalLayoutWidget_2);
        open_com_button->setObjectName(QString::fromUtf8("open_com_button"));

        horizontalLayout_3->addWidget(open_com_button);

        comboBox = new QComboBox(horizontalLayoutWidget_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(470, 110, 171, 28));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        rot_button = new QPushButton(horizontalLayoutWidget_3);
        rot_button->setObjectName(QString::fromUtf8("rot_button"));

        horizontalLayout_4->addWidget(rot_button);

        dir_checkbox = new QCheckBox(horizontalLayoutWidget_3);
        dir_checkbox->setObjectName(QString::fromUtf8("dir_checkbox"));

        horizontalLayout_4->addWidget(dir_checkbox);

        save_button = new QPushButton(centralwidget);
        save_button->setObjectName(QString::fromUtf8("save_button"));
        save_button->setGeometry(QRect(170, 400, 80, 26));
        horizontalLayoutWidget_4 = new QWidget(centralwidget);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(470, 140, 171, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setSpacing(1);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        angle_label = new QLabel(horizontalLayoutWidget_4);
        angle_label->setObjectName(QString::fromUtf8("angle_label"));

        horizontalLayout_5->addWidget(angle_label);

        angle_line_edit = new QLineEdit(horizontalLayoutWidget_4);
        angle_line_edit->setObjectName(QString::fromUtf8("angle_line_edit"));

        horizontalLayout_5->addWidget(angle_line_edit);

        horizontalLayoutWidget_5 = new QWidget(centralwidget);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(470, 170, 171, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        auto_button = new QPushButton(horizontalLayoutWidget_5);
        auto_button->setObjectName(QString::fromUtf8("auto_button"));

        horizontalLayout_6->addWidget(auto_button);

        auto_box = new QComboBox(horizontalLayoutWidget_5);
        auto_box->setObjectName(QString::fromUtf8("auto_box"));

        horizontalLayout_6->addWidget(auto_box);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(440, 90, 231, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(440, 210, 231, 16));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(450, 230, 211, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        camera_label = new QLabel(verticalLayoutWidget_2);
        camera_label->setObjectName(QString::fromUtf8("camera_label"));

        horizontalLayout_9->addWidget(camera_label);

        camera_status = new QLabel(verticalLayoutWidget_2);
        camera_status->setObjectName(QString::fromUtf8("camera_status"));

        horizontalLayout_9->addWidget(camera_status);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        com_label = new QLabel(verticalLayoutWidget_2);
        com_label->setObjectName(QString::fromUtf8("com_label"));

        horizontalLayout_8->addWidget(com_label);

        com_status = new QLabel(verticalLayoutWidget_2);
        com_status->setObjectName(QString::fromUtf8("com_status"));

        horizontalLayout_8->addWidget(com_status);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        zhengfan_label = new QLabel(verticalLayoutWidget_2);
        zhengfan_label->setObjectName(QString::fromUtf8("zhengfan_label"));

        horizontalLayout_7->addWidget(zhengfan_label);

        zhengfan_stauts = new QLabel(verticalLayoutWidget_2);
        zhengfan_stauts->setObjectName(QString::fromUtf8("zhengfan_stauts"));

        horizontalLayout_7->addWidget(zhengfan_stauts);


        verticalLayout_2->addLayout(horizontalLayout_7);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        camera_info_button->setText(QApplication::translate("MainWindow", "\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        construct_button->setText(QApplication::translate("MainWindow", "\345\205\211\350\260\261\351\207\215\346\236\204", nullptr));
        spectral_curve_button->setText(QApplication::translate("MainWindow", "\345\205\211\350\260\261\346\233\262\347\272\277", nullptr));
        camera_image_label->setText(QString());
        openCameraButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
        open_com_button->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "/dev/ttyUSB0", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "/dev/ttyUSB1", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "/dev/ttyUSB2", nullptr));

        rot_button->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254", nullptr));
        dir_checkbox->setText(QApplication::translate("MainWindow", "\346\255\243/\345\217\215", nullptr));
        save_button->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        angle_label->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254\350\247\222\345\272\246\357\274\232", nullptr));
        auto_button->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\213\215\347\205\247", nullptr));
        camera_label->setText(QApplication::translate("MainWindow", "\347\233\270\346\234\272\347\212\266\346\200\201\357\274\232", nullptr));
        camera_status->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        com_label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\347\212\266\346\200\201\357\274\232", nullptr));
        com_status->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        zhengfan_label->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254\346\226\271\345\220\221\357\274\232", nullptr));
        zhengfan_stauts->setText(QApplication::translate("MainWindow", "\346\255\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
