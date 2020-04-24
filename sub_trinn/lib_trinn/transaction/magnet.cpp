#include "transaction/magnet.h"

Trinn::transaction::Magnet::Magnet(AFIdObjectPtr object, QObject *parent)
    : QObject(parent), AFIdObject(object)
{
    //
}

Trinn::transaction::Magnet::Magnet(QObject* parent) : QObject(parent)
{
    //
}

QDate Trinn::transaction::Magnet::date() const
{
    return getAttribute(AFlib::Attribute::Date).toDate();
}

QTime Trinn::transaction::Magnet::time() const
{
    return getAttribute(AFlib::Attribute::Time).toTime();
}

double Trinn::transaction::Magnet::value() const
{
    return getAttribute <TrinnAttribute> (TrinnAttribute::TransactionValue).toDouble();
}

CurrencyEnum Trinn::transaction::Magnet::currency() const
{
    return static_cast <CurrencyEnum> (getAttribute(TrinnAttribute::TargetCurrency).toUInt());
}

double Trinn::transaction::Magnet::currencyCoef() const
{
    return getAttribute(TrinnAttribute::CurrencyCoeficient).toDouble();
}

void Trinn::transaction::Magnet::setDate(const QDate &date)
{
    if (this->date() == date)
        return;

    History::setAttribute(AFlib::Attribute::Date, date);
    emit dateChanged(date);
}

void Trinn::transaction::Magnet::setTime(const QTime& time)
{
    if (this->time() == time)
        return;

    History::setAttribute(AFlib::Attribute::Time, time);
    emit timeChanged(time);
}

void Trinn::transaction::Magnet::setValue(double value)
{
    if (qFuzzyCompare(this->value(), value))
        return;

    History::setAttribute <TrinnAttribute> (TrinnAttribute::TransactionValue, value);
    emit valueChanged(value);
}

void Trinn::transaction::Magnet::setCurrency(CurrencyEnum currency)
{
    if (currency == this->currency())
        return;

    setAttribute(TrinnAttribute::TargetCurrency, static_cast <uint>(currency));
    // TODO add signal for this
}

void Trinn::transaction::Magnet::setCurrencyCoef(double newCurrencyCoef)
{
    if (qFuzzyCompare(currencyCoef(), newCurrencyCoef))
        return;

    setAttribute(TrinnAttribute::CurrencyCoeficient, newCurrencyCoef);
    emit currencyCoefChanged(newCurrencyCoef);
}
