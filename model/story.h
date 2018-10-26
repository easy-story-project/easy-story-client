#ifndef STORY_H
#define STORY_H

#include <QObject>
#include <QDir>
#include <QVector>

#include "actor.h"

class Story : public QObject
{
    Q_OBJECT
public:
    explicit Story(const QString& uuid, const QString& name, const QDir& dir);

    static Story* create(const QString& name);
    static Story* load(const QString& uuid, const QString& name);
public:
    void setDir(QDir dir);
    QString getUUID();
    QString getName();

    void addActor(Actor* ac);

    void save();
    void load();

    friend QDataStream& operator<<(QDataStream&, const Story&);
    friend QDataStream& operator>>(QDataStream&, Story&);

public slots:
    void setName(QString name);

private:
    QString uuid;
    QString name;
    QDir dir;

public:
    QVector<Actor*> actors;
};

#endif // STORY_H
