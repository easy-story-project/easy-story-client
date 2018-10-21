#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>

#include "define.h"

class Database : public QObject
{
    Q_OBJECT
public:
    static Database* get();
    static void init();

    void upgrade();

private:
    explicit Database();

private:
    void buildNameTable();

signals:
    void signalDBInitBegin();
    void signalDBInitDone();
    void signalBuileDB(qreal progress);

public slots:

private:
    static Database* sInstance;

    QSqlDatabase sql;
    QSqlError error;
};

#endif // DATABASE_H
