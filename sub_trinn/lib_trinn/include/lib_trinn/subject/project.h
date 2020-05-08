#ifndef TRINN_LIB_SUBJECT_PROJECT_H
#define TRINN_LIB_SUBJECT_PROJECT_H

#include <AFbaseLib>

namespace Trinn::subject {
    class Project;
    typedef QSharedPointer <Project> ProjectPtr;
}

class Trinn::subject::Project : public AFIdObjectTemplate
{
    Q_OBJECT
public:
    explicit Project(QObject *parent = nullptr);
    Project(AFIdObjectPtr ptr,  QObject *parent = nullptr);
    virtual ~Project() = default;
};

#endif //TRINN_LIB_SUBJECT_PROJECT_H
