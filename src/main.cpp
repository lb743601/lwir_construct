#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w(nullptr);
    w.show();
    return a.exec();
}
