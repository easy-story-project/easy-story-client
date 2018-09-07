#ifndef THREADCENTER_H
#define THREADCENTER_H

#include <QObject>
#include <QThreadPool>

class ThreadCenter
{
private:
    explicit ThreadCenter();

public:
    static void init();

    static ThreadCenter* get();

public:
    void execute(QRunnable* task);

signals:

public slots:

private:
    QThreadPool pool;
    static ThreadCenter* sInstance;
};



#endif // THREADCENTER_H
