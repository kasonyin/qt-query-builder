#ifndef INSERTMODEL_H
#define INSERTMODEL_H

#include "sqlmodel.h"

class InsertModel : public SqlModel
{
public:
    explicit InsertModel() {}
    explicit InsertModel(const QString &column, const QVariant &value);
    virtual ~InsertModel() {}

    InsertModel &operator() (const QString &column, const QVariant &value);
    InsertModel &operator() (const QVector<QVariant> &values);
    InsertModel into(const QString &table_name);

    virtual QString build();
private:
    QString _table_name;
    QStringList _columns;
    QStringList _values;
};

#endif // INSERTMODEL_H
