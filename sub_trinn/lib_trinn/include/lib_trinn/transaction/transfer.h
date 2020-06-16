#ifndef TRINN_LIB_TRANSACTION_TRANSFER_H
#define TRINN_LIB_TRANSACTION_TRANSFER_H

#include <Trinn/Transaction/Magnet>
#include <Trinn/Subject/Account>

namespace Trinn::transaction {
    class Transfer;
    typedef QSharedPointer <Transfer> TransferPtr;
}

class Trinn::transaction::Transfer : public Magnet
{
    Q_OBJECT
public:
    explicit Transfer(QObject* parent = nullptr);
    Transfer(AFIdObjectPtr ptr,  QObject* parent = nullptr);
    virtual ~Transfer() = default;

    void setSender   (const TrinnAccountPtr sender);
    virtual subject::AccountPtr sender()   const final;
    virtual AFIdGlobal_bit      senderId() const final;

    void setRecipient(const TrinnAccountPtr recipient);
    virtual subject::AccountPtr recipient()   const final;
    virtual AFIdGlobal_bit      recipientId() const final;

public slots:
    // TODO add pointers
    void setSender(AFIdGlobal_bit sender);
    void setRecipient(AFIdGlobal_bit recipient);

signals:
    void senderChanged();
    void recipientChanged();
};

#endif
