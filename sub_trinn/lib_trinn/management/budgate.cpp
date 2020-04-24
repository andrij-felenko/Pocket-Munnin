#include "management/budgate.h"

Trinn::management::Budgate::Budgate(QObject *parent) : QObject(parent)
{
    //
}

Trinn::management::Budgate::Budgate(AFIdObjectPtr ptr, QObject *parent)
    : Budgate(ptr.data(), parent)
{
    //
}

Trinn::management::Budgate::Budgate(AFIdObject *object, QObject *parent)
    : QObject(parent), AFIdObject(object)
{
    //
}
