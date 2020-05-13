#include "management/plan.h"
#include "trinnStorage.h"

Trinn::management::Plan::Plan(QObject *parent)
    : AFIdObjectTemplate(pluginId, typeToInt(Type::Plan), parent)
{
    //
}

Trinn::management::Plan::Plan(AFIdObjectPtr ptr, QObject *parent)
    : AFIdObjectTemplate(ptr, parent)
{
    //
}
