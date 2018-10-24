#include "deletemodel.h"

DeleteModel::DeleteModel()
{

}

DeleteModel &DeleteModel::delete_()
{
    return *this;
}

DeleteModel &DeleteModel::from(const QString &table_name)
{
    _table_name = table_name;
    return *this;
}

DeleteModel &DeleteModel::where(const QString &condition)
{
    _where_conditions.append(condition);
    return *this;
}

DeleteModel &DeleteModel::where(const QString &column, const QString &condition)
{
    QString where_cond;
    where_cond.append(column).append(" ").append(condition);
    _where_conditions.append(where_cond);
    return *this;
}

DeleteModel &DeleteModel::where(const QString &column, const QString &condition, const QVariant &value)
{
    QString where_cond;
    where_cond.append(column).append(condition).append(this->toString(value));
    _where_conditions.append(where_cond);
    return *this;
}

QString DeleteModel::build()
{
    _sql.append("DELETE FROM ");
    _sql.append(_table_name);
    _sql.append(" ");

    int size = _where_conditions.size();
    if (size > 0) {
        _sql.append("WHERE ");
        for (int i = 0; i < size; i++) {
            _sql.append(_where_conditions.at(i)).append(" ");
        }
    }

    return _sql;
}
