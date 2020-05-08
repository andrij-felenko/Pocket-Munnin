#include "subject/store.h"

Trinn::subject::Store::Store(QObject *parent) : AFIdObjectTemplate(parent)
{
    //
}

Trinn::subject::Store::Store(AFIdObjectPtr ptr, QObject *parent)
    : AFIdObjectTemplate(ptr, parent)
{
    //
}
