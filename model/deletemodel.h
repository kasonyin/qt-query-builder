#ifndef DELETEMODEL_H
#define DELETEMODEL_H

#include "sqlmodel.h"

class DeleteModel : public SqlModel
{
public:
    explicit DeleteModel();
    virtual ~DeleteModel() {}
};

#endif // DELETEMODEL_H
