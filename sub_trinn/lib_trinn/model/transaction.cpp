#include "model/transaction.h"

Trinn::model::TransactionPtr modelTransactionPtr;

Trinn::model::TransactionPtr Trinn::modelTransaction()
{
    if (modelTransactionPtr.isNull())
        modelTransactionPtr = model::TransactionPtr::create();

    return modelTransactionPtr;
}

Trinn::model::Transaction::Transaction(QObject *parent) : QObject(parent)
{
    //
}
