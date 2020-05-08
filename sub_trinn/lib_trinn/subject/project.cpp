#include "subject/project.h"

Trinn::subject::Project::Project(QObject *parent) : AFIdObjectTemplate(parent)
{
    //
}

Trinn::subject::Project::Project(AFIdObjectPtr ptr, QObject *parent)
    : AFIdObjectTemplate(ptr, parent)
{
    //
}
