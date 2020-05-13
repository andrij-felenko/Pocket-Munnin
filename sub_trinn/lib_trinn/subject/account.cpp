#include "subject/account.h"
#include "trinnStorage.h"

static TrinnAccountPtr _defaultAccountPtr;

Trinn::subject::Account::Account(QObject *parent)
    : AFIdObjectTemplate(pluginId, typeToInt(Type::Account), parent)
{
    //
}

Trinn::subject::Account::Account(AFIdObjectPtr ptr, QObject *parent)
    : AFIdObjectTemplate(ptr, parent)
{
    //
}

bool Trinn::subject::Account::monoCurrency() const
{
    return AccountType::MonoCurrency == accountType();
}

Trinn::AccountType Trinn::subject::Account::accountType() const
{
    return static_cast <AccountType>(m_ptr->getAttribute(TrinnAttribute::AccountType).toUInt());
}

void Trinn::subject::Account::setAccountType(Trinn::AccountType type)
{
    if (accountType() == type)
        return;

    m_ptr->setAttribute(TrinnAttribute::AccountType, static_cast <uint> (type));
    emit monoCurrencyChanged(type == AccountType::MonoCurrency);
}

Trinn::subject::AccountPtr Trinn::subject::defaultAccountPtr()
{
    if (_defaultAccountPtr.isNull())
        _defaultAccountPtr = TrinnAccountPtr::create();
    return _defaultAccountPtr;
}
