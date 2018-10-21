#include "querybuilder.h"

QueryBuilder::QueryBuilder()
{

}

QueryBuilder::~QueryBuilder()
{
    if (_model != nullptr)
        delete _model;
}

SelectModel &QueryBuilder::select(QString columns)
{
    if (_model != nullptr)
        delete _model;

    _model = new SelectModel(columns);
    return *dynamic_cast<SelectModel *>(_model);
}

InsertModel &QueryBuilder::insert(const QVector<QVariant> &values)
{
    if (_model != nullptr)
        delete _model;

    _model = new InsertModel();
    (*dynamic_cast<InsertModel *>(_model))(values);
    return *dynamic_cast<InsertModel *>(_model);
}

InsertModel &QueryBuilder::insert(const QString &column, const QVariant &value)
{
    if (_model != nullptr)
        delete _model;

    _model = new InsertModel(column, value);
    return *dynamic_cast<InsertModel *>(_model);
}

UpdateModel &QueryBuilder::update(const QString &table_name)
{
    if (_model != nullptr)
        delete _model;

    _model = new UpdateModel(table_name);
    return *dynamic_cast<UpdateModel *>(_model);
}
