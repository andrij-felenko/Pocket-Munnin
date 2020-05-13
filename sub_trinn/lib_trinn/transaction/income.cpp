#include "transaction/income.h"
#include "model/subject.h"

Trinn::transaction::Income::Income(QObject* parent) : Magnet(Type::Income, parent)
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
    setCategory(category->afObject()->id());
}

void Trinn::transaction::Income::setRecipient(const TrinnAccountPtr recipient)
{
    setRecipient(recipient->afObject()->id());
}

Trinn::subject::AccountPtr Trinn::transaction::Income::recipient() const
{
    return modelSubject()->findAccount(recipientId());
}

Trinn::subject::CategoryPtr Trinn::transaction::Income::category() const
{
    return modelSubject()->findCategory(categoryId());
}

AFIdGlobal_bit Trinn::transaction::Income::recipientId() const
{
    return m_ptr->getIdAttribute(TrinnAttribute::Recipient);
}

AFIdGlobal_bit Trinn::transaction::Income::categoryId() const
{
    return m_ptr->getIdAttribute(TrinnAttribute::Category);
}

void Trinn::transaction::Income::setCategory(AFIdGlobal_bit category)
{
    if (category == categoryId())
        return;

    m_ptr->setIdAttribute(TrinnAttribute::Category, category);
    emit categoryChanged();
}

void Trinn::transaction::Income::setRecipient(AFIdGlobal_bit recipient)
{
    if (recipient == recipientId())
        return;

    m_ptr->setIdAttribute(TrinnAttribute::Recipient, recipient);
    emit recipientChanged();
}
