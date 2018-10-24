#ifndef CREATEMODEL_H
#define CREATEMODEL_H

#include "sqlmodel.h"

class CreateModel : public SqlModel
{
public:

    explicit CreateModel();
    ~CreateModel() {}

    CreateModel &create(const QString &table_name);
    CreateModel &notExist();

    CreateModel &increments(const QString &column_name);
    CreateModel &integer(const QString &column_name, quint32 length = 0);
    CreateModel &string(const QString &column_name, quint32 length = 0);

    CreateModel &primary();
    CreateModel &notNull();
    CreateModel &defaultIs(const QVariant &value);

    CreateModel &references(QString column_name);

    virtual QString build();
private:
    QString _table_name;
    QString _not_exist;
    QStringList _columns;
};

#endif // CREATEMODEL_H
