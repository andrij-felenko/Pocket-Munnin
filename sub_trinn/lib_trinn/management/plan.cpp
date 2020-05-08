#include "management/plan.h"

Trinn::management::Plan::Plan(QObject *parent) : AFIdObjectTemplate(parent)
{
    //
}

Trinn::management::Plan::Plan(AFIdObjectPtr ptr, QObject *parent)
    : AFIdObjectTemplate(ptr, parent)
{
    //
}
