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
    virtual QString build() = 0;
    // TODO
//    virtual QString get() = 0;

protected:
    QString toString(const QVariant &value)
    {
        QString v;
        if (QVariant::String == value.type()) {
            v.append("'");
            v.append(value.toString());
            v.append("'");
        } else {
            v = value.toString();
        }

        return v;
    }

protected:
    QString _sql;
};

#endif // SQLMODEL_H
