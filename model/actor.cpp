#include "actor.h"

#include <QDataStream>

Actor::Actor(QObject *parent) : QObject(parent)
{

}

QDataStream &operator<<(QDataStream &stream, const Actor &a)
{
    stream << a.name
           << a.boy
           << a.lead;
    return stream;
}

QDataStream &operator>>(QDataStream &stream, Actor &a)
{
    stream >> a.name;
    stream >> a.boy;
    stream >> a.lead;
    return stream;
}
