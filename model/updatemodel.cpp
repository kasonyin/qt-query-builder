#include "updatemodel.h"

UpdateModel::UpdateModel(const QString &table_name)
{
    _table_name = table_name;
}

UpdateModel &UpdateModel::set(const QString &column, const QVariant &value)
{
    _columns.append(column);
    // TODO
    _values.append(value.toString());
    return *this;
}

UpdateModel &UpdateModel::operator()(const QString &column, const QVariant &value)
{
    this->set(column, value);
    return *this;
}

UpdateModel &UpdateModel::where(const QString &condition)
{
    _where_conditions.append(condition);
    return *this;
}

UpdateModel &UpdateModel::where(const QString &column, const QString &condition)
{
    QString where_cond;
    where_cond.append(column).append(" ").append(condition);
    _where_conditions.append(where_cond);
    return *this;
}

UpdateModel &UpdateModel::where(const QString &column, const QString &condition, const QVariant &value)
{
    QString where_cond;
    where_cond.append(column).append(condition).append("'").append(value.toString()).append("'");
    _where_conditions.append(where_cond);
    return *this;
}

QString UpdateModel::build()
{
    _sql.append("UPDATE ").append(_table_name).append(" ");
    int size = _columns.size();
    for (int i = 0; i < size; i++) {
        _sql.append("SET ");
        _sql.append(_columns.at(i));
        _sql.append("=");
        _sql.append(_values.at(i));

        if (i == size - 1)
            _sql.append(" ");
        else
            _sql.append(", ");
    }

    size = _where_conditions.size();
    if (size > 0) {
        _sql.append("WHERE ");
        for (int i = 0; i < size; i++)
            _sql.append(_where_conditions.at(i)).append(" ");
    }

    return _sql;
}
