#include "transaction/magnet.h"
#include "trinnStorage.h"

Trinn::transaction::Magnet::Magnet(AFIdObjectPtr object, QObject *parent)
    : AFIdObjectTemplate(object, parent)
{
    //
}

Trinn::transaction::Magnet::Magnet(QObject* parent)
    : AFIdObjectTemplate(pluginId, typeToInt(Type::Magnet), parent)
{
    //
}

Trinn::transaction::Magnet::Magnet(Type type, QObject* parent)
    : AFIdObjectTemplate(pluginId, typeToInt(type), parent)
{
    //
}

QDate Trinn::transaction::Magnet::date() const
{
    return m_ptr->getAttribute(AFlib::Attribute::Date).toDate();
}

QTime Trinn::transaction::Magnet::time() const
{
    return m_ptr->getAttribute(AFlib::Attribute::Time).toTime();
}

double Trinn::transaction::Magnet::value() const
{
    return m_ptr->getAttribute <TrinnAttribute> (TrinnAttribute::TransactionValue).toDouble();
}

CurrencyEnum Trinn::transaction::Magnet::currency() const
{
    return static_cast <CurrencyEnum> (m_ptr->getAttribute(TrinnAttribute::TargetCurrency).toUInt());
}

double Trinn::transaction::Magnet::currencyCoef() const
{
    return m_ptr->getAttribute(TrinnAttribute::CurrencyCoeficient).toDouble();
}

void Trinn::transaction::Magnet::setDate(const QDate &date)
{
    if (this->date() == date)
        return;

    m_ptr->History::setAttribute(AFlib::Attribute::Date, date);
    emit dateChanged(date);
}

void Trinn::transaction::Magnet::setTime(const QTime& time)
{
    if (this->time() == time)
        return;

    m_ptr->History::setAttribute(AFlib::Attribute::Time, time);
    emit timeChanged(time);
}

void Trinn::transaction::Magnet::setValue(double value)
{
    if (qFuzzyCompare(this->value(), value))
        return;

    m_ptr->History::setAttribute <TrinnAttribute> (TrinnAttribute::TransactionValue, value);
    emit valueChanged(value);
}

void Trinn::transaction::Magnet::setCurrency(CurrencyEnum currency)
{
    if (currency == this->currency())
        return;

    m_ptr->setAttribute(TrinnAttribute::TargetCurrency, static_cast <uint>(currency));
    // TODO add signal for this
}

void Trinn::transaction::Magnet::setCurrencyCoef(double newCurrencyCoef)
{
    if (qFuzzyCompare(currencyCoef(), newCurrencyCoef))
        return;

    m_ptr->setAttribute(TrinnAttribute::CurrencyCoeficient, newCurrencyCoef);
    emit currencyCoefChanged(newCurrencyCoef);
}
