#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QRunnable>

class FileMonitor : public QRunnable
{
public:
    FileMonitor();

    void run() override;
};

#endif // FILEMONITOR_H
