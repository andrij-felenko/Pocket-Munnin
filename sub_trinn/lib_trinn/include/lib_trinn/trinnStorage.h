#ifndef TRINN_LIB_STORAGE_H
#define TRINN_LIB_STORAGE_H

#include "management/budgate.h"
#include "management/plan.h"
#include "subject/account.h"
#include "subject/category.h"
#include "subject/project.h"
#include "subject/store.h"
#include "transaction/income.h"
#include "transaction/purchase.h"
#include "transaction/transfer.h"

namespace Trinn {
    class Storage;

    typedef QSharedPointer <Storage> StoragePtr;
    typedef Storage    TransactionStorage;
    typedef StoragePtr TransactionStoragePtr;

    uint pluginId(3);
    StoragePtr storage();

    namespace model {
        class Plan;
        class Subject;
        class Transaction;
    }
}

class Trinn::Storage final : public QObject
{
public:
    explicit Storage(QObject* parent = nullptr);

private:
    void reload();

    std::vector <management::BudgatePtr> m_budgateV;
    std::vector <management::   PlanPtr>    m_planV;

    std::vector <subject:: AccountPtr>  m_accountV;
    std::vector <subject::CategoryPtr> m_categoryV;
    std::vector <subject:: ProjectPtr>  m_projectV;
    std::vector <subject::   StorePtr>    m_storeV;

    std::vector <transaction::  IncomePtr>   m_incomeV;
    std::vector <transaction::  MagnetPtr>   m_magnetV;
    std::vector <transaction::PurchasePtr> m_purchaseV;
    std::vector <transaction::TransferPtr> m_transferV;

    inline void clear();

    friend class model::Plan;
    friend class model::Subject;
    friend class model::Transaction;
};

Trinn::StoragePtr trinnStorage();

#endif
