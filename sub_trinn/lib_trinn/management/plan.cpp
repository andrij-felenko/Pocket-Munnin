#include "management/plan.h"

Trinn::management::Plan::Plan(QObject *parent) : QObject(parent)
{
    //
}

Trinn::management::Plan::Plan(AFIdObjectPtr ptr, QObject *parent)
    : Plan(ptr.data(), parent)
{
    //
}

Trinn::management::Plan::Plan(AFIdObject *object, QObject *parent)
    : QObject(parent), AFIdObject(object)
{
    //
}
