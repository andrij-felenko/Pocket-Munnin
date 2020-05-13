#ifndef TRINN_LIB_TRANSACTION_INCOME_H
#define TRINN_LIB_TRANSACTION_INCOME_H

#include <AFbaseLib>
#include "magnet.h"
#include "subject/account.h"
#include "subject/category.h"

namespace Trinn::transaction {
    class Income;
    typedef QSharedPointer <Income> IncomePtr;
}

class Trinn::transaction::Income : public Magnet
{
    Q_OBJECT
    // TODO add categoryFrom
public:
    explicit Income(QObject *parent = nullptr);
    Income(AFIdObjectPtr ptr,  QObject *parent = nullptr);
    virtual ~Income() = default;

    void setCategory (const TrinnCategoryPtr category);
    virtual subject::CategoryPtr category()   const final;
    virtual AFIdGlobal_bit       categoryId() const final;

    void setRecipient(const TrinnAccountPtr recipient);
    virtual subject::AccountPtr recipient()   const final;
    virtual AFIdGlobal_bit      recipientId() const final;

public slots:
    // TODO add pointers
    void setCategory (AFIdGlobal_bit category);
    void setRecipient(AFIdGlobal_bit recipient);

signals:
    void categoryChanged();
    void recipientChanged();
};

#endif
