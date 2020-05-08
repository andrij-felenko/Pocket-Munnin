#ifndef TRINN_LIB_TRANSACTION_MAGNET_H
#define TRINN_LIB_TRANSACTION_MAGNET_H

#include <QtCore/QDateTime>
#include <AFbaseLib>
#include <AFcurrencyLib>
#include "trinnEnum.h"

namespace Trinn::transaction {
    class Magnet;
    typedef QSharedPointer <Magnet> MagnetPtr;
}

class Trinn::transaction::Magnet : public AFIdObjectTemplate
{
    Q_OBJECT
    Q_PROPERTY(QDate  date     READ date    WRITE setDate    NOTIFY dateChanged)
    Q_PROPERTY(QTime  time     READ time    WRITE setTime    NOTIFY timeChanged)
    Q_PROPERTY(double value    READ value   WRITE setValue   NOTIFY valueChanged)
    // TODO add currency
    Q_PROPERTY(double  currencyCoef    READ currencyCoef NOTIFY currencyCoefChanged)
public:
    explicit Magnet(QObject *parent = nullptr);
    Magnet(AFIdObjectPtr ptr,  QObject *parent = nullptr);
    virtual ~Magnet() = default;

    virtual QDate  date()  const final;
    virtual QTime  time()  const final;
    virtual double value() const final;
    virtual CurrencyEnum currency() const final;
    virtual double currencyCoef()   const final;

public slots:
    virtual void setDate(const QDate &date)  final;
    virtual void setTime(const QTime &time)   final;
    virtual void setValue(double value) final;
    virtual void setCurrency(CurrencyEnum currency) final;
    virtual void setCurrencyCoef(double newCurrencyCoef) final;

signals:
    void dateChanged(QDate date);
    void timeChanged(QTime time);
    void valueChanged(double value);
    // TODO add currency
    void currencyCoefChanged(double newCurrencyCoef);
};

#endif
