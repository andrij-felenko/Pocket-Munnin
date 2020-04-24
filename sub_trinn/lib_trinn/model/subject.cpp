#include "model/subject.h"
#include "trinnStorage.h"

Trinn::model::SubjectPtr modelSubjectPtr;

Trinn::model::SubjectPtr Trinn::modelSubject()
{
    if (modelSubjectPtr.isNull())
        modelSubjectPtr = model::SubjectPtr::create();

    return modelSubjectPtr;
}

Trinn::model::Subject::Subject(QObject *parent) : QObject(parent)
{
    //
}

Trinn::subject::AccountPtr Trinn::model::Subject::findAccount(AFIdObject_bit id)
{
    for (auto it : trinnStorage()->m_accountV)
        if (it->object_b() == id)
            return it;
    return subject::AccountPtr();
}

Trinn::subject::CategoryPtr Trinn::model::Subject::findCategory(AFIdObject_bit id)
{
    for (auto it : trinnStorage()->m_categoryV)
        if (it->object_b() == id)
            return it;
    return subject::CategoryPtr();
}

Trinn::subject::ProjectPtr Trinn::model::Subject::findProject(AFIdObject_bit id)
{
    for (auto it : trinnStorage()->m_projectV)
        if (it->object_b() == id)
            return it;
    return subject::ProjectPtr();
}

Trinn::subject::StorePtr Trinn::model::Subject::findStore(AFIdObject_bit id)
{
    for (auto it : trinnStorage()->m_storeV)
        if (it->object_b() == id)
            return it;
    return subject::StorePtr();
}
