#include "transaction/purchase.h"
#include "model/subject.h"

Trinn::transaction::Purchase::Purchase(QObject* parent) : Magnet(parent)
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
    setSender(sender->afObject()->object_b().toUInt64());
}

Trinn::subject::AccountPtr Trinn::transaction::Purchase::sender() const
{
    return modelSubject()->findAccount(senderId());
}

AFIdObject_bit Trinn::transaction::Purchase::senderId() const
{
    return AFIdObject_bit(m_ptr->getAttribute(TrinnAttribute::Sender).toUInt());
}

void Trinn::transaction::Purchase::setCategory(const TrinnAccountPtr category)
{
    setCategory(category->afObject()->object_b().toUInt64());
}

Trinn::subject::CategoryPtr Trinn::transaction::Purchase::category() const
{
    return modelSubject()->findCategory(categoryId());
}

AFIdObject_bit Trinn::transaction::Purchase::categoryId() const
{
    return AFIdObject_bit(m_ptr->getAttribute(TrinnAttribute::Category).toUInt());
}

void Trinn::transaction::Purchase::setStore(const TrinnStorePtr store)
{
    setStore(store->afObject()->object_b().toUInt64());
}

Trinn::subject::StorePtr Trinn::transaction::Purchase::store() const
{
    return modelSubject()->findStore(storeId());
}

AFIdObject_bit Trinn::transaction::Purchase::storeId() const
{
    return AFIdObject_bit(m_ptr->getAttribute(TrinnAttribute::Store).toUInt());
}

void Trinn::transaction::Purchase::setCategory(quint64 category)
{
    if (category == categoryId().toUInt64())
        return;

    m_ptr->setAttribute(TrinnAttribute::Category, category);
    emit categoryChanged();
}

void Trinn::transaction::Purchase::setSender(quint64 sender)
{
    if (sender == senderId().toUInt64())
        return;

    m_ptr->setAttribute(TrinnAttribute::Sender, sender);
    emit senderChanged();
}

void Trinn::transaction::Purchase::setStore(quint64 store)
{
    if (store == storeId().toUInt64())
        return;

    m_ptr->setAttribute(TrinnAttribute::Store, store);
    emit storeChanged();
}
