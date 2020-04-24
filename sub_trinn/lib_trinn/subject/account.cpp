#include "subject/account.h"

static TrinnAccountPtr _defaultAccountPtr;

Trinn::subject::Account::Account(QObject *parent) : QObject(parent)
{
    //
}

Trinn::subject::Account::Account(AFIdObjectPtr ptr, QObject *parent)
    : Account(ptr.data(), parent)
{
    //
}

Trinn::subject::Account::Account(AFIdObject *object, QObject *parent)
    : QObject(parent), AFIdObject(object)
{
    //
}

bool Trinn::subject::Account::monoCurrency() const
{
    return AccountType::MonoCurrency == accountType();
}

Trinn::AccountType Trinn::subject::Account::accountType() const
{
    return static_cast <AccountType>(getAttribute(TrinnAttribute::AccountType).toUInt());
}

void Trinn::subject::Account::setAccountType(Trinn::AccountType type)
{
    if (accountType() == type)
        return;

    setAttribute(TrinnAttribute::AccountType, static_cast <uint> (type));
    emit monoCurrencyChanged(type == AccountType::MonoCurrency);
}

Trinn::subject::AccountPtr Trinn::subject::defaultAccountPtr()
{
    if (_defaultAccountPtr.isNull())
        _defaultAccountPtr = TrinnAccountPtr::create();
    return _defaultAccountPtr;
}
