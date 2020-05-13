#include "transaction/transfer.h"
#include "model/subject.h"

Trinn::transaction::Transfer::Transfer(QObject* parent) : Magnet(Type::Transfer, parent)
{
    //
}

Trinn::transaction::Transfer::Transfer(AFIdObjectPtr ptr, QObject* parent)
    : Magnet(ptr, parent)
{
    //
}

void Trinn::transaction::Transfer::setSender(const TrinnAccountPtr sender)
{
    setSender(sender->afObject()->id());
}

void Trinn::transaction::Transfer::setRecipient(const TrinnAccountPtr recipient)
{
    setRecipient(recipient->afObject()->id());
}

Trinn::subject::AccountPtr Trinn::transaction::Transfer::recipient() const
{
    return modelSubject()->findAccount(recipientId());
}

Trinn::subject::AccountPtr Trinn::transaction::Transfer::sender() const
{
    return modelSubject()->findAccount(senderId());
}

AFIdGlobal_bit Trinn::transaction::Transfer::recipientId() const
{
    return m_ptr->getIdAttribute(TrinnAttribute::Recipient);
}

AFIdGlobal_bit Trinn::transaction::Transfer::senderId() const
{
    return m_ptr->getIdAttribute(TrinnAttribute::Sender);
}

void Trinn::transaction::Transfer::setSender(AFIdGlobal_bit sender)
{
    if (sender == senderId())
        return;

    m_ptr->setIdAttribute(TrinnAttribute::Sender, sender);
    emit senderChanged();
}

void Trinn::transaction::Transfer::setRecipient(AFIdGlobal_bit recipient)
{
    if (recipient == recipientId())
        return;

    m_ptr->setIdAttribute(TrinnAttribute::Recipient, recipient);
    emit recipientChanged();
}
