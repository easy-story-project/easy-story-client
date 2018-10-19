#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>

class Actor : public QObject
{
    Q_OBJECT
public:
    explicit Actor(QObject *parent = nullptr);

signals:

public slots:

private:
    bool lead;
};

#endif // ACTOR_H
