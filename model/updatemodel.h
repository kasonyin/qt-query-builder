#ifndef UPDATEMODEL_H
#define UPDATEMODEL_H

#include "sqlmodel.h"

class UpdateModel : public SqlModel
{
public:
    explicit UpdateModel(const QString &table_name);
    virtual ~UpdateModel() {}

    UpdateModel &set(const QString &column, const QVariant &value);
    UpdateModel &operator() (const QString &column, const QVariant &value);

    UpdateModel &where(const QString &condition);
    UpdateModel &where(const QString &column, const QString &condition);
    UpdateModel &where(const QString &column, const QString &condition, const QVariant &value);

    virtual QString build();

private:
    QString _table_name;
    QStringList _columns;
    QStringList _values;
    QStringList _where_conditions;
};

#endif // UPDATEMODEL_H
