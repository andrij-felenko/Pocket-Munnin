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
        if (it->afObject()->object_b()==  id)
            return it;
    return subject::AccountPtr();
}

Trinn::subject::CategoryPtr Trinn::model::Subject::findCategory(AFIdObject_bit id)
{
    for (auto it : trinnStorage()->m_categoryV)
        if (it->afObject()->object_b() == id)
            return it;
    return subject::CategoryPtr();
}

Trinn::subject::ProjectPtr Trinn::model::Subject::findProject(AFIdObject_bit id)
{
    for (auto it : trinnStorage()->m_projectV)
        if (it->afObject()->object_b() == id)
            return it;
    return subject::ProjectPtr();
}

Trinn::subject::StorePtr Trinn::model::Subject::findStore(AFIdObject_bit id)
{
    for (auto it : trinnStorage()->m_storeV)
        if (it->afObject()->object_b() == id)
            return it;
    return subject::StorePtr();
}

void Trinn::model::Subject::restructorCategory()
{
    for (auto it : storage()->m_categoryV)
        if (it->afObject()->object_b().template parentType <Type>() == Type::Category)
            if (it->afObject()->parentId() != 0)
                for (auto parentIt : storage()->m_categoryV){
                    parentIt->addSubCategory(it);
                    break;
                }
}
