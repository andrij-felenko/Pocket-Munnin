#include "transaction/magnet.h"

Trinn::Magnet::Magnet(QString title, Trinn::Id id, QObject *parent)
    : Base(title, id, parent)
{
    //
}

Trinn::Magnet::Magnet(QString title, uint user, uint id, QObject *parent)
    : Magnet(title, Id(user, LotType::Transaction, Id::unite(2, 3, Ttype::Magnet, 19, id)), parent)
{
    //
}

Trinn::Ttype Trinn::Magnet::type() const
{
    return Ttype(lotId() >> 19);
}

QDate Trinn::Magnet::date() const
{
    return m_date;
}

QTime Trinn::Magnet::time() const
{
    return m_time;
}

double Trinn::Magnet::value() const
{
    return m_value;
}

QString Trinn::Magnet::descr() const
{
    return m_descr;
}

quint64 Trinn::Magnet::account() const
{
    return m_account;
}

void Trinn::Magnet::setDate(QDate date)
{
    if (m_date == date)
        return;

    m_date = date;
    emit dateChanged(m_date);
    lastTimeUpdate();
}

void Trinn::Magnet::setTime(QTime time)
{
    if (m_time == time)
        return;

    m_time = time;
    emit timeChanged(m_time);
    lastTimeUpdate();
}

void Trinn::Magnet::setDescr(QString descr)
{
    if (m_descr == descr)
        return;

    m_descr = descr;
    emit descrChanged(m_descr);
    lastTimeUpdate();
}

void Trinn::Magnet::setValue(double value)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_value, value))
        return;

    m_value = value;
    emit valueChanged(m_value);
    lastTimeUpdate();
}

void Trinn::Magnet::setAccount(quint64 account)
{
    if (m_account == account)
        return;

    m_account = account;
    emit accountChanged(m_account);
    lastTimeUpdate();
}
