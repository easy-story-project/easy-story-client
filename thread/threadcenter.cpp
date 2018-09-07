#include "threadcenter.h"

ThreadCenter* ThreadCenter::sInstance = nullptr;

ThreadCenter::ThreadCenter()
{
}

void ThreadCenter::init()
{
    get();
}

ThreadCenter *ThreadCenter::get()
{
    if (sInstance == nullptr)
        sInstance = new ThreadCenter();
    return sInstance;
}

void ThreadCenter::execute(QRunnable *task)
{
    pool.tryStart(task);
}
