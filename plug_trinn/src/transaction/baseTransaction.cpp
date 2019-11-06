#include "transaction/baseTransaction.h"

Trinn::BaseTransaction::BaseTransaction(QString title, Id id, QObject* parent)
    : Magnet(title, id, parent)
{
    //
}

Trinn::BaseTransaction::BaseTransaction(QString title, uint user, uint id, QObject *parent)
    : BaseTransaction(title, Id(user, LotType::Transaction, Id::unite(2, 3, Ttype::Magnet, 19, id)), parent)
{
    //
}

quint64 Trinn::BaseTransaction::sender() const
{
    return m_account;
}

quint64 Trinn::BaseTransaction::recipient() const
{
    return m_recipient;
}

double Trinn::BaseTransaction::currencyCoef() const
{
    return m_currencyCoef;
}

void Trinn::BaseTransaction::setSender(quint64 sender)
{
    if (sender != m_account){
        setAccount(sender);
        emit senderChanged(sender);
        lastTimeUpdate();
    }
}

void Trinn::BaseTransaction::setRecipient(quint64 recipient)
{
    if (m_recipient == recipient)
        return;

    m_recipient = recipient;
    emit recipientChanged(m_recipient);
    lastTimeUpdate();
}

void Trinn::BaseTransaction::setCurrencyCoef(double currencyCoef)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_currencyCoef, currencyCoef))
        return;

    m_currencyCoef = currencyCoef;
    emit currencyCoefChanged(m_currencyCoef);
    lastTimeUpdate();
}
