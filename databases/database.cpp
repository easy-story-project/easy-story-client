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
        throw new SqlCreateFailed("无法打开数据库");
    }

    QSqlQuery query;
    QStringList tables = sql.tables();
    if (!tables.contains("story")) {
        query.prepare(QLatin1String("create table story (id integer primary key, uuid varchar, name varchar, created datetime)"));
        if (!query.exec()) {
            qDebug() << tr("Table `story` Create failed:") << query.lastError();
        } else {
            qDebug() << tr("Table `story` Create OK");
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
