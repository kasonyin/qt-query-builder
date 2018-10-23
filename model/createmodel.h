#ifndef CREATEMODEL_H
#define CREATEMODEL_H

#include "sqlmodel.h"

class CreateModel : public SqlModel
{
public:
    CreateModel(QString table_name);

    CreateModel &increments(QString column_name);
    CreateModel &integer(QString column_name);
    CreateModel &string(QString column_name);


    CreateModel &notExist();
    CreateModel &references(QString column_name);


private:
    QString _table_name;
};

#endif // CREATEMODEL_H
