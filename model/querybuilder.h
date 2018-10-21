#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <QString>
#include <QVariant>

#include "sqlmodel.h"
#include "selectmodel.h"
#include "insertmodel.h"
#include "updatemodel.h"

class QueryBuilder
{
public:
    explicit QueryBuilder();
    ~QueryBuilder();

    SelectModel &select(QString columns);

    InsertModel &insert(const QVector<QVariant> &values);
    InsertModel &insert(const QString &column, const QVariant &value);

    UpdateModel &update(const QString &table_name);

private:
    SqlModel *_model = nullptr;
};

#endif // QUERYBUILDER_H
