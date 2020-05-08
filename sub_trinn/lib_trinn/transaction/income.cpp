#include "transaction/income.h"
#include "model/subject.h"

Trinn::transaction::Income::Income(QObject* parent) : Magnet(parent)
{
    //
}

Trinn::transaction::Income::Income(AFIdObjectPtr ptr,  QObject* parent)
    : Magnet(ptr, parent)
{
    //
}

void Trinn::transaction::Income::setCategory(const TrinnCategoryPtr category)
{
    setCategory(category->afObject()->object_b().toUInt64());
}

void Trinn::transaction::Income::setRecipient(const TrinnAccountPtr recipient)
{
    setRecipient(recipient->afObject()->object_b().toUInt64());
}

Trinn::subject::AccountPtr Trinn::transaction::Income::recipient() const
{
    return modelSubject()->findAccount(recipientId());
}

Trinn::subject::CategoryPtr Trinn::transaction::Income::category() const
{
    return modelSubject()->findCategory(categoryId());
}

AFIdObject_bit Trinn::transaction::Income::recipientId() const
{
    return AFIdObject_bit(m_ptr->getAttribute(TrinnAttribute::Recipient).toUInt());
}

AFIdObject_bit Trinn::transaction::Income::categoryId() const
{
    return AFIdObject_bit(m_ptr->getAttribute(TrinnAttribute::Sender).toUInt());
}

void Trinn::transaction::Income::setCategory(quint64 category)
{
    if (category == categoryId().toUInt64())
        return;

    m_ptr->setAttribute(TrinnAttribute::Category, category);
    emit categoryChanged();
}

void Trinn::transaction::Income::setRecipient(quint64 recipient)
{
    if (recipient == recipientId().toUInt64())
        return;

    m_ptr->setAttribute(TrinnAttribute::Recipient, recipient);
    emit recipientChanged();
}
