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

void Database::buildNameTable()
{
    QSqlQueryModel model;
    model.setQuery("SELECT word_key FROM name_build");
    int rowCount = model.rowCount();

    QSqlQuery query;
    query.exec("SELECT word_key FROM name_build");
    int rows = query.numRowsAffected();
    int size = query.size();
    if (size > 0) {
        qDebug() << "数据库已初始化..";
        return;
    }

    emit signalDBInitBegin();
    qDebug() << "初始化数据库.." << rows;

    QDir dir("://res/sqls/insert");
    QFileInfoList files = dir.entryInfoList();
    for (QFileInfo file : files) {
        qDebug() << "开始导入文件: " << file.filePath();
        QFile sql(file.filePath());
        if (!sql.open(QIODevice::ReadOnly|QIODevice::Text)) {
            continue;
        }

        QTextStream in(&sql);
        in.setCodec("UTF-8");

        int count = 0;
        int failed = 0;
        while (!in.atEnd()) {
            QString str = in.readLine();
            if(!query.exec(str)) {
                qDebug() << str << "初始化数据失败!!\n";
                failed++;
            } else {
                count++;
            }
        }

        qDebug() << file.filePath() << "Done!! count:" << count << "failed:" << failed;
    }

    emit signalDBInitDone();
}

void Database::upgrade()
{

    buildNameTable();
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


