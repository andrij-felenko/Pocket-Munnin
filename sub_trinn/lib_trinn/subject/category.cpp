#include "subject/category.h"

Trinn::subject::Category::Category(QObject *parent) : QObject(parent)
{
    //
}

Trinn::subject::Category::Category(AFIdObjectPtr ptr, QObject *parent)
    : QObject(parent), AFIdObject(ptr.data())
{
    //
}

Trinn::subject::Category::Category(AFIdObject *object, QObject *parent)
    : QObject(parent), AFIdObject(object)
{
    //
}
