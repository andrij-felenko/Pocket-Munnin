#ifndef TRINN_LIB_MODEL_MANAGEMENT_H
#define TRINN_LIB_MODEL_MANAGEMENT_H

#include <AFbaseLib>
#include <Management/Budgate>
#include <Management/Plan>

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
