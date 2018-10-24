#ifndef DELETEMODEL_H
#define DELETEMODEL_H

#include "sqlmodel.h"

class DeleteModel : public SqlModel
{
public:
    explicit DeleteModel();
    virtual ~DeleteModel() {}

    DeleteModel &delete_();
    DeleteModel &from(const QString &table_name);

    DeleteModel &where(const QString &condition);
    DeleteModel &where(const QString &column, const QString &condition);
    DeleteModel &where(const QString &column, const QString &condition, const QVariant &value);

    virtual QString build();

private:
    QString _table_name;
    QStringList _where_conditions;
};

#endif // DELETEMODEL_H
