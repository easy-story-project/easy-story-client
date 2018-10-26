#include "mainwindow.h"
#include "thread/threadcenter.h"
#include "databases/database.h"
#include "databases/exceptions/sqlcreatefailed.h"

#include "model/chinesenamebuilder.h"

#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try {
        ThreadCenter::init();
        Database::init();
        Database::get()->upgrade();
    } catch (SqlCreateFailed& e) {
        qDebug() << "Sql create Failed: " << e.what();
        exit(0);
    }

    MainWindow w;
    w.show();

    return a.exec();
}
