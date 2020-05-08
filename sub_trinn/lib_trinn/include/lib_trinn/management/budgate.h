#ifndef TRINN_LIB_MANAGEMENT_BUDGET_H
#define TRINN_LIB_MANAGEMENT_BUDGET_H

#include <QtCore/QSharedPointer>
#include <AFbaseLib>

namespace Trinn::management {
    class Budgate;
    typedef QSharedPointer <Budgate> BudgatePtr;
}

class Trinn::management::Budgate : public AFIdObjectTemplate
{
    Q_OBJECT
public:
    explicit Budgate(QObject *parent = nullptr);
    Budgate(AFIdObjectPtr ptr,  QObject *parent = nullptr);
    virtual ~Budgate() = default;
};

#endif // TRINN_LIB_PLAN_BUDGET_H
