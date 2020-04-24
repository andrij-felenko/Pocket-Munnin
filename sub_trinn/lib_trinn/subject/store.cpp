#include "subject/store.h"

Trinn::subject::Store::Store(QObject *parent) : QObject(parent)
{
    //
}

Trinn::subject::Store::Store(AFIdObjectPtr ptr, QObject *parent)
    : Store(ptr.data(), parent)
{
    //
}

Trinn::subject::Store::Store(AFIdObject *object, QObject *parent)
    : QObject(parent), AFIdObject(object)
{
    //
}
