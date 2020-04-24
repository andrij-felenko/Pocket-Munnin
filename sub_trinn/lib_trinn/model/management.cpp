#include "model/management.h"

Trinn::model::ManagementPtr modelManagementPtr;

Trinn::model::ManagementPtr Trinn::modelManagement()
{
    if (modelManagementPtr.isNull())
        modelManagementPtr = model::ManagementPtr::create();

    return modelManagementPtr;
}

Trinn::model::Management::Management(QObject *parent) : QObject(parent)
{
    //
}
