#include "transaction/transfer.h"

Trinn::Transfer::Transfer(QString title, SubjectId id, QObject* parent)
    : BaseTransaction(title, id, parent)
{
    //
}

Trinn::Transfer::Transfer(QString title, uint user, uint id, QObject *parent )
    : Transfer(title, Id(user, uint(LotType::Transaction), Id::unite(2, 3, Ttype::Spend, 19, id)), parent)
{
    //
}

Trinn::Tconfirm Trinn::Transfer::confirm() const
{
    return m_confirm;
}

//void Trinn::Transfer::setProject(uint project)
//{
//    if (m_project == project)
//        return;

//    m_project = project;
//    emit projectChanged(m_project);
//}

void Trinn::Transfer::setConfirm(Trinn::TransactionConfirm confirm)
{
    if (m_confirm == confirm)
        return;

    m_confirm = confirm;
    emit confirmChanged(m_confirm);
    lastTimeUpdate();
}
