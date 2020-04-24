#ifndef TRINN_LIB_MANAGEMENT_PLAN_H
#define TRINN_LIB_MANAGEMENT_PLAN_H

#include <QtCore/QSharedPointer>
#include <AFbaseLib>

namespace Trinn::management {
    class Plan;
    typedef QSharedPointer <Plan> PlanPtr;
}

class Trinn::management::Plan : public QObject, public AFlib::id::Object
{
    Q_OBJECT
public:
    explicit Plan(QObject *parent = nullptr);
    Plan(AFIdObjectPtr ptr,  QObject *parent = nullptr);
    Plan(AFIdObject* object, QObject *parent = nullptr);
    virtual ~Plan() = default;
};

#endif // TRINN_LIB_PLAN_PLAN_H
