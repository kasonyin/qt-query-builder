#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include "sqlmodel.h"
#include "createmodel.h"
#include "insertmodel.h"
#include "selectmodel.h"
#include "updatemodel.h"
#include "deletemodel.h"
/*********************************************
 * 这里不用前置声明，是为了在使用时不需要引用
 * 太多文件，直接引用 querybuilder.h 就可以
 ********************************************/
class QueryBuilder
{
public:
    enum Type {
        Create,
        Insert,
        Select,
        Update,
        Delete
    };
    explicit QueryBuilder();
    ~QueryBuilder();

    CreateModel &create(const QString &table_name);
    SelectModel &select(const QString &columns);

    InsertModel &insert(const QVector<QVariant> &values);
    InsertModel &insert(const QString &column, const QVariant &value);

    UpdateModel &update(const QString &table_name);
    DeleteModel &delete_();
private:
    SqlModel *getModel(QueryBuilder::Type type);

private:
    SqlModel *_model = nullptr;
};

#endif // QUERYBUILDER_H
