#include "threadcenter.h"

ThreadCenter::ThreadCenter(QObject *parent)
    : QObject(parent)
{

}

void ThreadCenter::init()
{
    ThreadCenter::get();
}

ThreadCenter *ThreadCenter::get()
{
    if (sInstance == nullptr) {
        sInstance = new ThreadCenter();
    }

    return sInstance;
}
