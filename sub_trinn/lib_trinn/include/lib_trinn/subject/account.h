#ifndef TRINN_LIB_SUBJECT_ACCOUNT_H
#define TRINN_LIB_SUBJECT_ACCOUNT_H

#include <AFbaseLib>
#include <AFcurrencyLib>
#include <Trinn/Enum>

namespace Trinn::subject {
    class Account;
    typedef QSharedPointer <Account> AccountPtr;

    AccountPtr defaultAccountPtr();
}

class Trinn::subject::Account : public AFIdObjectTemplate
{
    Q_OBJECT
    Q_PROPERTY(bool monoCurrency READ monoCurrency NOTIFY monoCurrencyChanged)
public:
    explicit Account(QObject *parent = nullptr);
    Account(AFIdObjectPtr ptr,  QObject *parent = nullptr);
    virtual ~Account() = default;

    virtual bool monoCurrency() const final;
    virtual AccountType accountType() const;
    virtual void setAccountType(AccountType type);

signals:
    void monoCurrencyChanged(bool monoCurrency);

protected:
    CurrencyEnum m_currencyList;
};

typedef Trinn::subject::Account TrinnAccount;
typedef QSharedPointer <TrinnAccount> TrinnAccountPtr;

#endif //TRINN_LIB_SUBJECT_ACCOUNT_H
