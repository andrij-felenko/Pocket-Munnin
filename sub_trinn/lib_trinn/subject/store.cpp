#include "subject/store.h"
#include "trinnStorage.h"

Trinn::subject::Store::Store(QObject *parent)
    : AFIdObjectTemplate(pluginId, typeToInt(Type::Store), parent)
{
    //
}

Trinn::subject::Store::Store(AFIdObjectPtr ptr, QObject *parent)
    : AFIdObjectTemplate(ptr, parent)
{
    //
}
