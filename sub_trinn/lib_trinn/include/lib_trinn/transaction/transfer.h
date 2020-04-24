#ifndef TRINN_LIB_TRANSACTION_TRANSFER_H
#define TRINN_LIB_TRANSACTION_TRANSFER_H

#include "transaction/magnet.h"
#include "subject/account.h"

namespace Trinn::transaction {
    class Transfer;
    typedef QSharedPointer <Transfer> TransferPtr;
}

class Trinn::transaction::Transfer : public Magnet
{
    Q_OBJECT
public:
    explicit Transfer(QObject* parent = nullptr);
    Transfer(AFIdObject* object, QObject* parent = nullptr);
    Transfer(AFIdObjectPtr ptr,  QObject* parent = nullptr);
    virtual ~Transfer() = default;

    void setSender   (const TrinnAccountPtr sender);
    virtual subject::AccountPtr sender()   const final;
    virtual AFIdObject_bit      senderId() const final;

    void setRecipient(const TrinnAccountPtr recipient);
    virtual subject::AccountPtr recipient()   const final;
    virtual AFIdObject_bit      recipientId() const final;

public slots:
    // TODO add pointers
    void setSender(quint64 sender);
    void setRecipient(quint64 recipient);

signals:
    void senderChanged();
    void recipientChanged();
};

#endif
