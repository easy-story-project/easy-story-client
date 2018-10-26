#include "chinesenamebuilder.h"
#include <QtDebug>
#include <QFile>

#include <QDateTime>

ChineseNameBuilder::ChineseNameBuilder(bool boy) : QObject(nullptr),
    boy(boy)
{
    generateRandSeek();
    random = true;
}

ChineseNameBuilder::ChineseNameBuilder(bool sw, bool singleName, bool boy):QObject(nullptr),
    singleXing(sw),
    singleName(singleName),
    boy(boy)
{
    generateRandSeek();
    random = false;
}

const QString ChineseNameBuilder::build()
{
    if (random) {
        singleXing = qrand() % 100 > 20;
        singleName = (qrand() % 100) < 50;
    }

    QFile xingFile(singleXing? "://res/strings/xingS" : "://res/strings/xingD");
    if (!xingFile.open(QIODevice::ReadOnly|QIODevice::Text)) {
        return "";
    }

    QTextStream in(&xingFile);
    in.setCodec("UTF-8");

    QString str = in.readAll();
    QStringList xings = str.split('|');
    QString xing = xings.at(qrand() % xings.length());

    QFile nameFile(boy ? "://res/strings/name_word_boy" : "://res/strings/name_word_gril");
    if (!nameFile.open(QIODevice::ReadOnly|QIODevice::Text)) return "";

    QTextStream nameStream(&nameFile);
    nameStream.setCodec("UTF-8");

    QString name = xing;
    str = nameStream.readAll();
    int nameLen = singleName ? 1 : 2;
    for (int i=0; i<nameLen; i++) {
        name += str.at(qrand() % str.length());
    }

    return name;
}

void ChineseNameBuilder::generateRandSeek()
{
    uint seek = static_cast<uint>(time(nullptr));
    qsrand(seek);
}

