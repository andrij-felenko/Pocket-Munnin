#include "trinnStorage.h"
#include <AFaccountLib>
#include "model/subject.h"

static Trinn::TransactionStoragePtr storage_ptr;

Trinn::StoragePtr Trinn::storage()
{
    if (storage_ptr.isNull())
        storage_ptr = StoragePtr::create();
    return storage_ptr;
}

Trinn::Storage::Storage(QObject *parent) : QObject(parent)
{
    reload();
}

void Trinn::Storage::reload()
{
    clear();
    auto dependsAccount = AFaccount::storage()->dependsAccount();

    for (auto it : AFlib::afStorage()->getObjectList(dependsAccount, pluginId)){
        using namespace management;
        using namespace subject;
        using namespace transaction;

        switch (it->object_b().template type <Trinn::Type>()){

        case Type::Income:     m_incomeV.push_back(IncomePtr  ::create(it)); break;
        case Type::Magnet:     m_magnetV.push_back(MagnetPtr  ::create(it)); break;
        case Type::Purchase: m_purchaseV.push_back(PurchasePtr::create(it)); break;
        case Type::Transfer: m_transferV.push_back(TransferPtr::create(it)); break;

        case Type::Budgate:   m_budgateV.push_back(BudgatePtr ::create(it)); break;
        case Type::Plan:         m_planV.push_back(PlanPtr    ::create(it)); break;

        case Type::Account:   m_accountV.push_back(AccountPtr ::create(it)); break;
        case Type::Category: m_categoryV.push_back(CategoryPtr::create(it)); break;
        case Type::Project:   m_projectV.push_back(ProjectPtr ::create(it)); break;
        case Type::Store:       m_storeV.push_back(StorePtr   ::create(it)); break;

        case Type::None: qWarning() << "check it";
        }
    }

    // check all Account for trinn account, if not exist, we need to create this
    // TODO

    modelSubject()->restructorCategory();
}

void Trinn::Storage::clear()
{
    m_budgateV.clear();
    m_planV.clear();

    m_accountV.clear();
    m_categoryV.clear();
    m_projectV.clear();
    m_storeV.clear();

    m_incomeV.clear();
    m_magnetV.clear();
    m_purchaseV.clear();
    m_transferV.clear();
}

Trinn::StoragePtr trinnStorage()
{
    return Trinn::storage();
}
