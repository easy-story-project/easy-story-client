#ifndef CHINESENAMEBUILDER_H
#define CHINESENAMEBUILDER_H

#include <QObject>
#include <QVector>

class ChineseNameBuilder : public QObject
{
    Q_OBJECT

public:
    explicit ChineseNameBuilder(bool singleWord);

signals:

public slots:

private:
    bool singleWord;
    QVector<QString> surname;
};

#endif // CHINESENAMEBUILDER_H
