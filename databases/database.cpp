#include "database.h"

#include "exceptions/sqlcreatefailed.h"

#include <QtDebug>


Database* Database::sInstance = nullptr;

Database::Database() :
    QObject(nullptr),
    sql(QSqlDatabase::addDatabase("QSQLITE"))
{
    sql.setDatabaseName("book.db");
    if (!sql.open()) {
        error = sql.lastError();
        throw new SqlCreateFailed("cannot open DB");
    }

    QSqlQuery query;
    QStringList tables = sql.tables();
    if (tables.contains("worlds") && tables.contains("name_build")) {
        return ;
    }

    QDir dir("://res/sqls/create");
    QFileInfoList files = dir.entryInfoList();
    for (QFileInfo file : files) {
        qDebug() << file.filePath();
        QFile sqlFile(file.filePath());
        if (!sqlFile.open(QIODevice::ReadOnly)) {
            throw new SqlCreateFailed("cannot open sql:" + file.fileName());
        }

        QTextStream in(&sqlFile);
        QString str = in.readAll();
        qInfo() << str;
        query.prepare(str);
        if (!query.exec()) {
            throw new SqlCreateFailed("cannot open sql:" + file.fileName());
        }
        qInfo() << str << " OK";
    }
}

Database *Database::get()
{
    if (sInstance == nullptr)
        sInstance = new Database();

    return sInstance;
}

void Database::init()
{
    get();
}
