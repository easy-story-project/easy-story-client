#include "story.h"
#include "databases/database.h"

#include <QtDebug>
#include <QUuid>
#include <QDir>

Story::Story(const QString& uuid, const QString& name, const QDir& dir) :
    QObject(nullptr),
    uuid(uuid),
    name(name),
    dir(dir)
{

}

Story* Story::create(const QString& name)
{
    QString uuid = QUuid::createUuid().toString();
    QDir dir = QDir::currentPath();
    dir.mkdir("Projects");
    dir.cd("Projects");
    dir.mkdir(uuid);
    dir.cd(uuid);

    Story* story = new Story(uuid, name, dir);
    return story;
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

void Story::setName(QString name)
{
    this->name = name;
    qDebug() << "story set name successfuly: " << name;
}
