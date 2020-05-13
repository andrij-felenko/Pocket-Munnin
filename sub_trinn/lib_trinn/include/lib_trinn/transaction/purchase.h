#ifndef TRINN_LIB_TRANSACTION_PURCHASE_H
#define TRINN_LIB_TRANSACTION_PURCHASE_H

#include <AFbaseLib>
#include "magnet.h"
#include "subject/account.h"
#include "subject/category.h"
#include "subject/store.h"

namespace Trinn::transaction {
    class Purchase;
    typedef QSharedPointer <Purchase> PurchasePtr;
}

class Trinn::transaction::Purchase : public Magnet
{
    Q_OBJECT
public:
    explicit Purchase(QObject* parent = nullptr);
    Purchase(AFIdObjectPtr ptr,  QObject* parent = nullptr);
    virtual ~Purchase() = default;

    void setSender(const TrinnAccountPtr sender);
    virtual subject::AccountPtr sender()   const final;
    virtual AFIdGlobal_bit      senderId() const final;

    void setCategory(const TrinnAccountPtr category);
    virtual subject::CategoryPtr category()   const final;
    virtual AFIdGlobal_bit       categoryId() const final;

    void setStore(const TrinnStorePtr store);
    virtual subject::StorePtr store()   const final;
    virtual AFIdGlobal_bit    storeId() const final;

public slots:
    void setCategory(AFIdGlobal_bit category);
    void setSender(AFIdGlobal_bit sender);
    void setStore(AFIdGlobal_bit store);

signals:
    void categoryChanged();
    void senderChanged();
    void storeChanged();
};

#endif
