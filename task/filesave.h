#ifndef FILESAVE_H
#define FILESAVE_H

#include <QRunnable>

class FileSave : public QRunnable
{
public:
    FileSave();

    void run() override;
};

#endif // FILESAVE_H
