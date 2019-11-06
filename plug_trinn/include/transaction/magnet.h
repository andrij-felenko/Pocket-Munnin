#pragma once
#include <QtCore/QDateTime>
#include "type/base.h"

namespace Trinn {
class Magnet : public Base
{
    Q_OBJECT
    Q_PROPERTY(Ttype  type     READ type    CONSTANT)
    Q_PROPERTY(QDate  date     READ date    WRITE setDate    NOTIFY dateChanged)
    Q_PROPERTY(QTime  time     READ time    WRITE setTime    NOTIFY timeChanged)
    Q_PROPERTY(double value    READ value   WRITE setValue   NOTIFY valueChanged)
    Q_PROPERTY(QString descr   READ descr   WRITE setDescr   NOTIFY descrChanged)
    Q_PROPERTY(quint64 account READ account WRITE setAccount NOTIFY accountChanged)
public:
    explicit Magnet(QString title, uint user, uint id, QObject *parent = nullptr);
    virtual ~Magnet() = default;

    virtual Ttype  type()  const final;
    virtual QDate  date()  const final;
    virtual QTime  time()  const final;
    virtual double value() const final;
    virtual QString descr() const final;
    virtual quint64 account() const final;

public slots:
    virtual void setDate(QDate date)  final;
    virtual void setTime(QTime time)   final;
    virtual void setValue(double value) final;
    virtual void setDescr(QString descr) final;
    virtual void setAccount(quint64 account) final;

signals:
    void dateChanged(QDate date);
    void timeChanged(QTime time);
    void valueChanged(double value);
    void descrChanged(QString descr);
    void accountChanged(quint64 account);

protected:
    Magnet(QString title, Id id, QObject* parent = nullptr);
    QDate m_date;
    QTime m_time;
    double m_value;
    QString m_descr;
    quint64 m_account;
};
}
