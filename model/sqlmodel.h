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
            if (value.toString() != "NULL") {
                v.append("'");
                v.append(value.toString());
                v.append("'");
            } else {
                v.append(value.toString());
            }
        } else {
            v = value.toString();
        }

        return v;
    }

protected:
    QString _sql;
};

#endif // SQLMODEL_H
