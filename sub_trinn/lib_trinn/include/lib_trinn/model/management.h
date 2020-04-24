#ifndef TRINN_LIB_MODEL_MANAGEMENT_H
#define TRINN_LIB_MODEL_MANAGEMENT_H

#include <AFbaseLib>
#include "management/budgate.h"
#include "management/plan.h"

namespace Trinn {
    namespace model {
        class Management;
        typedef QSharedPointer <Management> ManagementPtr;
    }

    model::ManagementPtr modelManagement();
}

class Trinn::model::Management : public QObject
{
    Q_OBJECT
public:
    explicit Management(QObject *parent = nullptr);
    virtual ~Management() = default;
};

#endif
