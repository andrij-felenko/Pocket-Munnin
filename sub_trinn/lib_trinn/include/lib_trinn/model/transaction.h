#ifndef TRINN_LIB_MODEL_TRANSACTION_H
#define TRINN_LIB_MODEL_TRANSACTION_H

#include <AFbaseLib>
#include "transaction/income.h"
#include "transaction/magnet.h"
#include "transaction/purchase.h"
#include "transaction/transfer.h"

namespace Trinn {
    namespace model {
        class Transaction;
        typedef QSharedPointer <Transaction> TransactionPtr;
    }

    model::TransactionPtr modelTransaction();
}

class Trinn::model::Transaction : public QObject
{
    Q_OBJECT
public:
    explicit Transaction(QObject *parent = nullptr);
    virtual ~Transaction() = default;
};

#endif
