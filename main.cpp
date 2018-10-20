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
    } catch (SqlCreateFailed& e) {
        qDebug() << "Sql create Failed: " << e.what();
        exit(0);
    }

    ChineseNameBuilder builder(true, true, true);
    QString name = builder.build();
    qDebug() << name;

    MainWindow w;
    w.show();

    return a.exec();
}
