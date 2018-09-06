#include "filemonitor.h"
#include <QThread>

FileMonitor::FileMonitor()
{

}

void FileMonitor::run()
{
    QThread::sleep(100);
}
