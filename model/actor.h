#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>

class Actor : public QObject
{
    Q_OBJECT
public:
    explicit Actor(QObject *parent = nullptr);


    friend QDataStream& operator<<(QDataStream&, const Actor&);
    friend QDataStream& operator>>(QDataStream&, Actor&);

signals:

public slots:

public:
    QString uuid;
    QString name;
    bool lead;
    bool boy;
};

#endif // ACTOR_H
