#include "transaction/purchase.h"
#include "model/subject.h"

Trinn::transaction::Purchase::Purchase(QObject* parent) : Magnet(Type::Purchase, parent)
{
    //
}

Trinn::transaction::Purchase::Purchase(AFIdObjectPtr ptr,  QObject* parent)
    : Magnet(ptr, parent)
{
    //
}

void Trinn::transaction::Purchase::setSender(const TrinnAccountPtr sender)
{
    setSender(sender->afObject()->id());
}

Trinn::subject::AccountPtr Trinn::transaction::Purchase::sender() const
{
    return modelSubject()->findAccount(senderId());
}

AFIdGlobal_bit Trinn::transaction::Purchase::senderId() const
{
    return m_ptr->getIdAttribute(TrinnAttribute::Sender);
}

void Trinn::transaction::Purchase::setCategory(const TrinnAccountPtr category)
{
    setCategory(category->afObject()->id());
}

Trinn::subject::CategoryPtr Trinn::transaction::Purchase::category() const
{
    return modelSubject()->findCategory(categoryId());
}

AFIdGlobal_bit Trinn::transaction::Purchase::categoryId() const
{
    return m_ptr->getIdAttribute(TrinnAttribute::Category);
}

void Trinn::transaction::Purchase::setStore(const TrinnStorePtr store)
{
    setStore(store->afObject()->id());
}

Trinn::subject::StorePtr Trinn::transaction::Purchase::store() const
{
    return modelSubject()->findStore(storeId());
}

AFIdGlobal_bit Trinn::transaction::Purchase::storeId() const
{
    return m_ptr->getIdAttribute(TrinnAttribute::Store);
}

void Trinn::transaction::Purchase::setCategory(AFIdGlobal_bit category)
{
    if (category == categoryId())
        return;

    m_ptr->setIdAttribute(TrinnAttribute::Category, category);
    emit categoryChanged();
}

void Trinn::transaction::Purchase::setSender(AFIdGlobal_bit sender)
{
    if (sender == senderId())
        return;

    m_ptr->setIdAttribute(TrinnAttribute::Sender, sender);
    emit senderChanged();
}

void Trinn::transaction::Purchase::setStore(AFIdGlobal_bit store)
{
    if (store == storeId())
        return;

    m_ptr->setIdAttribute(TrinnAttribute::Store, store);
    emit storeChanged();
}
