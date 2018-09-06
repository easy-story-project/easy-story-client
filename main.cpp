#include "mainwindow.h"
#include "thread/threadcenter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThreadCenter::init();

    MainWindow w;
    w.show();

    return a.exec();
}
