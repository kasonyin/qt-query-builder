#ifndef SELECTMODEL_H
#define SELECTMODEL_H

#include "sqlmodel.h"
class SelectModel : public SqlModel
{
public:
    explicit SelectModel() {}
    virtual ~SelectModel() {}

    SelectModel &select(const QString &select_columns = "*");
    SelectModel &from(const QString &table_name);
    SelectModel &where(const QString &condition);
    SelectModel &where(const QString &column, const QString &condition);
    SelectModel &where(const QString &column, const QString &condition, const QVariant &value);
    SelectModel &groupBy(const QString &column);
    SelectModel &having(const QString &condition);
    SelectModel &orderBy(const QString &order_by);
    SelectModel &limit(const quint32 &limit);
    SelectModel &offset(const quint32 &offset);

    SelectModel &clear();

    virtual QString build();
protected:
    QString _table_name;
    QString _select_column;
    QStringList _where_conditions;
    QStringList _groupby_columns;
    QStringList _having_conditions;
    QString _order_by;
    QString _limit;
    QString _offset;
};

#endif // SELECTMODEL_H
