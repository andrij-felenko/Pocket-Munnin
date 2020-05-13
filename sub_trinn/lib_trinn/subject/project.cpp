#include "subject/project.h"
#include "trinnStorage.h"

Trinn::subject::Project::Project(QObject *parent)
    : AFIdObjectTemplate(pluginId, typeToInt(Type::Project), parent)
{
    //
}

Trinn::subject::Project::Project(AFIdObjectPtr ptr, QObject *parent)
    : AFIdObjectTemplate(ptr, parent)
{
    //
}
