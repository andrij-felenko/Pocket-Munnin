#include "management/budgate.h"
#include "trinnEnum.h"
#include "trinnStorage.h"

Trinn::management::Budgate::Budgate(QObject *parent)
    : AFIdObjectTemplate(pluginId, typeToInt(Type::Budgate), parent)
{
    //
}

Trinn::management::Budgate::Budgate(AFIdObjectPtr ptr, QObject *parent)
    : AFIdObjectTemplate(ptr, parent)
{
    //
}
