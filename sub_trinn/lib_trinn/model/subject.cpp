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

Trinn::subject::AccountPtr Trinn::model::Subject::findAccount(AFIdGlobal_bit id)
{
    for (auto it : trinnStorage()->m_accountV)
        if (it->afObject()->globalId() == id)
            return it;
    return subject::AccountPtr();
}

Trinn::subject::CategoryPtr Trinn::model::Subject::findCategory(AFIdGlobal_bit id)
{
    for (auto it : trinnStorage()->m_categoryV)
        if (it->afObject()->globalId() == id)
            return it;
    return subject::CategoryPtr();
}

Trinn::subject::ProjectPtr Trinn::model::Subject::findProject(AFIdGlobal_bit id)
{
    for (auto it : trinnStorage()->m_projectV)
        if (it->afObject()->globalId() == id)
            return it;
    return subject::ProjectPtr();
}

Trinn::subject::StorePtr Trinn::model::Subject::findStore(AFIdGlobal_bit id)
{
    for (auto it : trinnStorage()->m_storeV)
        if (it->afObject()->globalId() == id)
            return it;
    return subject::StorePtr();
}

void Trinn::model::Subject::restructorCategory()
{
    for (const auto &it : storage()->m_categoryV)
        if (it->afObject()->parent().template type <Type>() == Type::Category)
            if (not it->afObject()->parent().isEmpty())
                for (auto parentIt : storage()->m_categoryV){
                    parentIt->addSubCategory(it);
                    break;
                }
}
