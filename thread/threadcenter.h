#ifndef THREADCENTER_H
#define THREADCENTER_H

#include <QObject>
#include <QThreadPool>

class ThreadCenter : public QObject
{
    Q_OBJECT
public:
    explicit ThreadCenter(QObject *parent = nullptr);
    static void init();

    static ThreadCenter* get();

signals:

public slots:

private:
    QThreadPool pool;
    static ThreadCenter* sInstance;
};

#endif // THREADCENTER_H
