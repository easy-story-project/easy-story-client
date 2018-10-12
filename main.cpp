#include "mainwindow.h"
#include "thread/threadcenter.h"
#include "databases/database.h"
#include "databases/exceptions/sqlcreatefailed.h"
#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try {
        ThreadCenter::init();
        Database::init();

    } catch (SqlCreateFailed& e) {
        qDebug() << "Sql create Failed.";
        exit(0);
    }

    MainWindow w;
    w.show();

    return a.exec();
}
