#ifndef SQLCREATEFAILED_H
#define SQLCREATEFAILED_H

#include <stdexcept>
#include <QString>
using namespace std;

class SqlCreateFailed : public exception
{
public:
    SqlCreateFailed(const QString& what);
};

#endif // SQLCREATEFAILED_H
