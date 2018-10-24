#include "selectmodel.h"

SelectModel::SelectModel(const QString &slect_columns)
{
    _select_column = slect_columns;
}

SelectModel &SelectModel::select(const QString &select_columns)
{
    _select_column = select_columns;
    return *this;
}

SelectModel &SelectModel::from(const QString &table_name)
{
    _table_name = table_name;
    return *this;
}

SelectModel &SelectModel::where(const QString &condition)
{
    _where_conditions.append(condition);
    return *this;
}

SelectModel &SelectModel::where(const QString &column, const QString &condition)
{
    QString where_cond;
    where_cond.append(column).append(" ").append(condition);
    _where_conditions.append(where_cond);
    return *this;
}

SelectModel &SelectModel::where(const QString &column, const QString &condition, const QVariant &value)
{
    QString where_cond;
    where_cond.append(column).append(condition).append(this->toString(value));
    _where_conditions.append(where_cond);
    return *this;
}

SelectModel &SelectModel::groupBy(const QString &column)
{
    _groupby_columns.append(column);
    return *this;
}

SelectModel &SelectModel::having(const QString &condition)
{
    _having_conditions.append(condition);
    return *this;
}

SelectModel &SelectModel::orderBy(const QString &order_by)
{
    _order_by = order_by;
    return *this;
}

SelectModel &SelectModel::limit(const quint32 &limit)
{
    _limit = QString::number(limit);
    return *this;
}

SelectModel &SelectModel::offset(const quint32 &offset)
{
    _offset = QString::number(offset);
    return *this;
}

SelectModel &SelectModel::clear()
{
    _table_name.clear();
    _select_column.clear();
    _groupby_columns.clear();
    _where_conditions.clear();
    _having_conditions.clear();
    _order_by.clear();
    _limit.clear();
    _offset.clear();
    return *this;
}

QString SelectModel::build()
{
    int size = 0;
    _sql.clear();
    _sql.append("SELECT ").append(_select_column).append(" ");
    _sql.append("FROM ").append(_table_name).append(" ");

    size = _where_conditions.size();
    if (size > 0) {
        _sql.append("WHERE ");
        for (int i = 0; i < size; i++) {
            _sql.append(_where_conditions.at(i)).append(" ");
        }
    }

    size = _groupby_columns.size();
    if (size > 0) {
        _sql.append("GROUP BY ");
        for (int i = 0; i < size; i++) {
            if (i < size - 1)
                _sql.append(_groupby_columns.at(i)).append(", ");
            else
                _sql.append(_groupby_columns.at(i)).append(" ");
        }
    }

    size = _having_conditions.size();
    if (size > 0) {
        _sql.append("HAVING ");
        for (int i = 0; i < size; i++) {
            _sql.append(_having_conditions.at(i)).append(" ");
        }
    }

    if (!_order_by.isEmpty()) {
        _sql.append("ORDER BY ").append(_order_by);
    }

    if (!_limit.isEmpty()) {
        _sql.append(" LIMIT ").append(_limit);
    }

    if (!_offset.isEmpty()) {
        _sql.append(" OFFSET ").append(_offset);
    }

    return _sql;
}
