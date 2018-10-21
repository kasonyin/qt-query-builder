#ifndef SQLMODEL_H
#define SQLMODEL_H

#include <QString>
#include <QVariant>
#include <QVector>

class SqlModel
{
public:
    SqlModel(){}
    virtual ~SqlModel(){}
//    virtual QString get() = 0;
    virtual QString build() = 0;

protected:
//    QString to_value(const QVariant &value)
//    {
//        bool ok = false;
//    }

protected:
    QString _sql;
};

#endif // SQLMODEL_H
