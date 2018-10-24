#include "insertmodel.h"

InsertModel::InsertModel(const QString &column, const QVariant &value)
{
    _columns.append(column);
    _values.append(this->toString(value));
}

InsertModel &InsertModel::operator()(const QString &column, const QVariant &value)
{
    _columns.append(column);
    _values.append(this->toString(value));
    return *this;
}

InsertModel &InsertModel::operator()(const QVector<QVariant> &values)
{
    for (int i = 0; i < values.size(); i++) {
        _values.append(this->toString(values.at(i)));
    }

    return *this;
}

InsertModel InsertModel::into(const QString &table_name)
{
    _table_name = table_name;
    return *this;
}

QString InsertModel::build()
{
    int size = 0;
    _sql.append("INSERT INTO ").append(_table_name).append(" ");

    size = _columns.size();
    if (size > 0 ) {
        _sql.append("(");
        _sql.append(_columns.join(","));
        _sql.append(") ");
        _sql.append("VALUES(");
        _sql.append(_values.join(",")).append(")");
    } else {
        _sql.append("VALUES(");
        _sql.append(_values.join(","));
        _sql.append(")");
    }

    return _sql;
}
