#include "transaction/spend.h"

Trinn::Spend::Spend(QString title, Id id, QObject* parent)
    : BaseTransaction(title, id, parent)
{
    //
}

Trinn::Spend::Spend(QString title, uint user, uint id, QObject *parent )
    : Spend(title, Id(user, LotType::Transaction, Id::unite(2, 3, Ttype::Spend, 19, id)), parent)
{
    //
}

//uint Trinn::Spend::project() const
//{
//    return m_project;
//}

uint Trinn::Spend::category() const
{
    return m_category;
}

quint64 Trinn::Spend::merchant() const
{
    return m_recipient;
}

//void Trinn::Spend::setProject(uint project)
//{
//    if (m_project == project)
//        return;

//    m_project = project;
//    emit projectChanged(m_project);
//}

void Trinn::Spend::setCategory(uint category)
{
    if (m_category == category)
        return;

    m_category = category;
    emit categoryChanged(m_category);
    lastTimeUpdate();
}

void Trinn::Spend::setMerchant(quint64 merchant)
{
    if (m_recipient == merchant){
        setRecipient(merchant);
        emit merchantChanged(merchant);
    }
}
