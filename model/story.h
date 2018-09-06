#ifndef STORY_H
#define STORY_H

#include <QObject>

class Story : public QObject
{
    Q_OBJECT
public:
    explicit Story(QObject *parent = nullptr);

signals:

public slots:
};

#endif // STORY_H