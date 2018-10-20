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

void Database::upgrade()
{
    QSqlQuery query;
    query.exec("SELECT word_key FROM name_build");
    int size = query.size();
    qDebug() << "upgrade:" << size;

    if (size <= 0) {
        QDir dir("://res/sqls/insert");
        QFileInfoList files = dir.entryInfoList();
        for (QFileInfo file : files) {
            qDebug() << file.filePath();
            QFile sql(file.filePath());
            if (!sql.open(QIODevice::ReadOnly)) {
                continue;
            }

            QTextStream in(&sql);
            QString str = in.readAll();
            if(!query.exec(str)) qDebug() << str << "初始化数据失败!!\n";
        }
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


