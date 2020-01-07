#ifndef TRINNENUM_H
#define TRINNENUM_H

#include <QtCore/QObject>

namespace Trinn {
    Q_NAMESPACE
    enum class TransactionConfirm {
        No_required = 0,
        Waiting,
        Received,
    };

    enum class TransactionType { // 3 bit
        None = 0,
        Transfer,
        Income,
        Magnet,
        Spend,
        Plan,
    };

    enum class LotType { // 4 bit
        None = 0,
        Card,
        Currency,
        Merchant,
        Category,
        Project,
        Transaction,
    };

    typedef TransactionType    Ttype;
    typedef TransactionConfirm Tconfirm;
}

#endif // TRINNENUM_H
