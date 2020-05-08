#include "transaction/transfer.h"
#include "model/subject.h"

Trinn::transaction::Transfer::Transfer(QObject* parent) : Magnet(parent)
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
    setSender(sender->afObject()->object_b().toUInt64());
}

void Trinn::transaction::Transfer::setRecipient(const TrinnAccountPtr recipient)
{
    setRecipient(recipient->afObject()->object_b().toUInt64());
}

Trinn::subject::AccountPtr Trinn::transaction::Transfer::recipient() const
{
    return modelSubject()->findAccount(recipientId());
}

Trinn::subject::AccountPtr Trinn::transaction::Transfer::sender() const
{
    return modelSubject()->findAccount(senderId());
}

AFIdObject_bit Trinn::transaction::Transfer::recipientId() const
{
    return AFIdObject_bit(m_ptr->getAttribute(TrinnAttribute::Recipient).toUInt());
}

AFIdObject_bit Trinn::transaction::Transfer::senderId() const
{
    return AFIdObject_bit(m_ptr->getAttribute(TrinnAttribute::Sender).toUInt());
}

void Trinn::transaction::Transfer::setSender(quint64 sender)
{
    if (sender == senderId().toUInt64())
        return;

    m_ptr->setAttribute(TrinnAttribute::Sender, sender);
    emit senderChanged();
}

void Trinn::transaction::Transfer::setRecipient(quint64 recipient)
{
    if (recipient == recipientId().toUInt64())
        return;

    m_ptr->setAttribute(TrinnAttribute::Recipient, recipient);
    emit recipientChanged();
}
