#include "database.h"

#include "exceptions/sqlcreatefailed.h"
#include "define.h"

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

    QDir dir("://res/sqls/create");
    QFileInfoList files = dir.entryInfoList();
    for (QFileInfo file : files) {
        qDebug() << "Create Table " << file.fileName() << "...";
        QString tableName = file.fileName();
        if (tables.contains(tableName))
            continue;

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
        qInfo() << "Create Table " << file.fileName() << " OK";
    }
}

void Database::buildNameTable()
{
    qDebug() << "初始化数据库..";
    emit signalDBInitBegin();

    QString tableName = "name_build";
    if (checkInitialStatus(tableName)) {
        qDebug() << "name_build" << tr(" 数据库已初始化..");
        return;
    }

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
        QSqlQuery query;

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
        emit signalDBInitDone(file.fileName());
    }

    setInitialStatus(tableName);
}

bool Database::checkInitialStatus(QString table)
{
    QSqlQueryModel model;
    QString sql = QString("SELECT * FROM setup WHERE name='%1'").arg(table);
    model.setQuery(sql);
    int rows = model.rowCount();
    return rows > 0;
}

void Database::setInitialStatus(QString table)
{
    QSqlTableModel model;
    model.setTable("setup");
    QSqlRecord record = model.record();
    record.setValue("name", table);
    model.insertRecord(model.rowCount(), record);
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


