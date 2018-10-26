#ifndef CHINESENAMEBUILDER_H
#define CHINESENAMEBUILDER_H

#include <QObject>
#include <QVector>
#include <QMap>
#include <QRandomGenerator>

class ChineseNameBuilder : public QObject
{
    Q_OBJECT

public:
    explicit ChineseNameBuilder(bool boy);
    explicit ChineseNameBuilder(bool singleX, bool singleName, bool boy);

    const QString build();

private:
    void generateRandSeek();

signals:

public slots:

private:
    bool random;
    bool singleXing;
    bool singleName;
    bool boy;

    QRandomGenerator generator;
};

#endif // CHINESENAMEBUILDER_H
