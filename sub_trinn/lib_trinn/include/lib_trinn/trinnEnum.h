#ifndef TRINN_LIB_ENUM_H
#define TRINN_LIB_ENUM_H

#include <QtCore/QObject>

namespace Trinn {
    Q_NAMESPACE
    enum class TransactionConfirm {
        No_required = 0,
        Waiting,
        Received,
    };

    enum class Type { // 3 bit
        None = 0,
        Income,
        Magnet,
        Purchase,
        Transfer,
        Budgate,
        Plan,
        Account,
        Category,
        Project,
        Store,
    };

    enum class TrinnAttribute {
        TransactionValue = 0,
        AccountType,
        CurrencyCoeficient,
        Sender,
        Recipient,
        TargetCurrency,
        Category,
        Store,
        Project,
    };

    enum class AccountType {
        MonoCurrency = 0,
        PolyCurrency,
    };

    typedef TransactionConfirm Tconfirm;
}

#endif
