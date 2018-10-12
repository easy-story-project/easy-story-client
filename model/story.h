#ifndef STORY_H
#define STORY_H

#include <QObject>
#include <QDir>

class Story : public QObject
{
    Q_OBJECT
public:
    explicit Story(const QString& uuid, const QString& name, const QDir& dir);

    static Story* create(const QString& name);
    static Story* load(const QString& name);
public:
    void setDir(QDir dir);
    QString getUUID();
    QString getName();

public slots:
    void setName(QString name);

private:
    QString uuid;
    QString name;
    QDir dir;
};

#endif // STORY_H
