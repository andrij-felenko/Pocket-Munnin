#ifndef TRINN_LIB_MODEL_SUBJECT_H
#define TRINN_LIB_MODEL_SUBJECT_H

#include <AFbaseLib>
#include "subject/account.h"
#include "subject/category.h"
#include "subject/project.h"
#include "subject/store.h"

namespace Trinn {
    namespace model {
        class Subject;
        typedef QSharedPointer <Subject> SubjectPtr;
    }

    model::SubjectPtr modelSubject();
}

class Trinn::model::Subject : public QObject
{
    Q_OBJECT
public:
    explicit Subject(QObject *parent = nullptr);
    virtual ~Subject() = default;

    Trinn::subject::AccountPtr  findAccount (AFIdGlobal_bit id);
    Trinn::subject::CategoryPtr findCategory(AFIdGlobal_bit id);
    Trinn::subject::ProjectPtr  findProject (AFIdGlobal_bit id);
    Trinn::subject::StorePtr    findStore   (AFIdGlobal_bit id);

    void restructorCategory();
};

#endif
