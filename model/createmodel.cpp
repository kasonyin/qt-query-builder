#include "createmodel.h"

CreateModel::CreateModel()
{

}

CreateModel &CreateModel::create(const QString &table_name)
{
    _table_name = table_name;
    return *this;
}

CreateModel &CreateModel::notExist()
{
    _not_exist = QString("IF NOT EXIST ");
    return *this;
}

CreateModel &CreateModel::increments(const QString &column_name)
{
    QString column;
    column.append(column_name);
    column.append(" INTEGER AUTOINCREMENT");
    _columns.append(column);
    return *this;
}

CreateModel &CreateModel::integer(const QString &column_name, quint32 length)
{
    QString column;
    column.append(column_name).append(" INTEGER ");
    if (0 != length)
        column.append("(").append(length).append(")");

    _columns.append(column);
    return *this;
}

CreateModel &CreateModel::string(const QString &column_name, quint32 length)
{
    QString column;
    column.append(column_name).append(" ");
    if (0 != length) {
        column.append(" VARCHAR");
        column.append("(");
        column.append(length);
        column.append(")");
    } else {
        column.append("TEXT ");
    }
    _columns.append(column);
    return *this;
}

CreateModel &CreateModel::primary()
{
    QString &str = _columns.last();
    if (str.contains("AUTOINCREMENT")) {
        str.insert(str.indexOf("AUTOINCREMENT"), "PRIMARY KEY ");
    } else {
        str.append("PRIMARY KEY ");
    }

    return *this;
}

CreateModel &CreateModel::notNull()
{
    QString &str = _columns.last();
    str.append(" NOT NULL");
    return *this;
}

CreateModel &CreateModel::defaultIs(const QVariant &value)
{
    QString &str = _columns.last();
    str.append(" DEFAULT ").append(this->toString(value));
    return *this;
}

CreateModel &CreateModel::references(QString column_name)
{
    return *this;
}

QString CreateModel::build()
{
    _sql.append("CREATE TABLE ");
    _sql.append(_not_exist);
    _sql.append(_table_name).append(" (");

    int size = _columns.size();
    for (int i = 0; i < size; i++) {
        if (i == size -1)
            _sql.append(_columns.at(i));
        else
            _sql.append(_columns.at(i)).append(",");
    }

    _sql.append(")");

    return _sql;
}
