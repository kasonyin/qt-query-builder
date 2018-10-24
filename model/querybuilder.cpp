#include "querybuilder.h"

QueryBuilder::QueryBuilder()
{

}

QueryBuilder::~QueryBuilder()
{
    if (_model != nullptr)
        delete _model;
}

CreateModel &QueryBuilder::create(const QString &table_name)
{
    this->getModel(Create);
    (*dynamic_cast<CreateModel *>(_model)).create(table_name);
    return *dynamic_cast<CreateModel *>(_model);
}

SelectModel &QueryBuilder::select(const QString &columns)
{
    this->getModel(Select);
    (*dynamic_cast<SelectModel *>(_model)).select(columns);
    return *dynamic_cast<SelectModel *>(_model);
}

InsertModel &QueryBuilder::insert(const QVector<QVariant> &values)
{
    this->getModel(Insert);
    (*dynamic_cast<InsertModel *>(_model))(values);
    return *dynamic_cast<InsertModel *>(_model);
}

InsertModel &QueryBuilder::insert(const QString &column, const QVariant &value)
{
    this->getModel(Insert);
    (*dynamic_cast<InsertModel *>(_model))(column, value);
    return *dynamic_cast<InsertModel *>(_model);
}

UpdateModel &QueryBuilder::update(const QString &table_name)
{
    this->getModel(Update);
    (*dynamic_cast<UpdateModel *>(_model)).table(table_name);
    return *dynamic_cast<UpdateModel *>(_model);
}

SqlModel *QueryBuilder::getModel(QueryBuilder::Type type)
{
    if (_model != nullptr)
        delete  _model;

    switch (type) {
    case Create: _model = new CreateModel;  break;
    case Insert: _model = new InsertModel;  break;
    case Select: _model = new SelectModel;  break;
    case Update: _model = new UpdateModel;  break;
    default: break;
    }

    return _model;
}
