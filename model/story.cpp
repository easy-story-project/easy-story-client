#include "story.h"
#include "databases/database.h"

#include <QtDebug>
#include <QUuid>
#include <QDir>
#include <QDataStream>

Story::Story(const QString& uuid, const QString& name, const QDir& dir) :
    QObject(nullptr),
    uuid(uuid),
    name(name),
    dir(dir)
{
    load();
}

Story* Story::create(const QString& name)
{
    QString uuid = QUuid::createUuid().toString();
    QDir dir = QDir::currentPath();
    dir.mkdir("Projects");
    dir.cd("Projects");
    dir.mkdir(uuid);
    dir.cd(uuid);

    return new Story(uuid, name, dir);
}

Story *Story::load(const QString &uuid, const QString &name)
{
    QDir dir = QDir::currentPath();
    dir.mkdir("Projects");
    dir.cd("Projects");
    dir.mkdir(uuid);
    dir.cd(uuid);
    return new Story(uuid, name, dir);
}

void Story::setDir(QDir dir)
{
    this->dir = dir;
}

QString Story::getUUID()
{
    return uuid;
}

QString Story::getName()
{
    return name;
}

void Story::addActor(Actor *ac)
{
    actors.append(ac);
}

void Story::save()
{
    QFile file(uuid);
    if (!file.open(QIODevice::ReadWrite))
        return ;

    QDataStream dataStream(&file);
    dataStream << *this;
}

void Story::load()
{
    QFile file(uuid);
    if (!file.open(QIODevice::ReadOnly))
        return ;

    QDataStream stream(&file);
    stream >> *this;
}

QDataStream &operator<<(QDataStream &stream, const Story & s)
{
    stream << s.uuid;
    stream << s.name;
    stream << s.actors.length();
    for (Actor* a : s.actors) {
        stream << *a;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, Story &s)
{
    int actorLength = 0;
    stream >> s.uuid
            >> s.name
            >> actorLength;
    for (int i = 0; i < actorLength; i++) {
        Actor* actor = new Actor();
        stream >> *actor;
        s.addActor(actor);
    }

    return stream;
}

void Story::setName(QString name)
{
    this->name = name;
    qDebug() << "story set name successfuly: " << name;
}
