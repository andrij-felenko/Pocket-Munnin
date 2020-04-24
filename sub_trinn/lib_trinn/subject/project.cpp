#include "subject/project.h"

Trinn::subject::Project::Project(QObject *parent) : QObject(parent)
{
    //
}

Trinn::subject::Project::Project(AFIdObjectPtr ptr, QObject *parent)
    : Project(ptr.data(), parent)
{
    //
}

Trinn::subject::Project::Project(AFIdObject *object, QObject *parent)
    : QObject(parent), AFIdObject(object)
{
    //
}
