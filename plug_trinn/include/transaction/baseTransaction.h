#pragma once
#include <QtCore/QDateTime>
#include "magnet.h"

namespace Trinn {
class BaseTransaction : public Magnet
{
    Q_OBJECT
    Q_PROPERTY(quint64 sender READ sender WRITE setSender NOTIFY senderChanged)
    Q_PROPERTY(quint64 recipient READ recipient WRITE setRecipient NOTIFY recipientChanged)
    Q_PROPERTY(double  currencyCoef READ currencyCoef WRITE setCurrencyCoef NOTIFY currencyCoefChanged)
public:
    explicit BaseTransaction(QString title, uint user, uint id, QObject *parent = nullptr);
    virtual ~BaseTransaction() = default;

    virtual quint64 sender() const final;
    virtual quint64 recipient() const final;
    virtual double currencyCoef() const final;

public slots:
    void setSender(quint64 sender);
    void setRecipient(quint64 recipient);
    void setCurrencyCoef(double currencyCoef);

signals:
    void senderChanged(quint64 sender);
    void recipientChanged(quint64 recipient);
    void currencyCoefChanged(double currencyCoef);

protected:
    BaseTransaction(QString title, SubjectId id, QObject* parent = nullptr);
    quint64 m_recipient;
    double m_currencyCoef;
};
}
