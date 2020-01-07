#pragma once
#include "type/base.h"
#include "currencyType.h"

namespace Trinn {
class TrinnSubjectId;
class TrinnProtoSubject;
}

class Subject : public Base
{
    Q_OBJECT
    Q_PROPERTY(QString uid READ uid WRITE setUid NOTIFY uidChanged)
    Q_PROPERTY(AFlib::SubjectType subjectType READ subjectType CONSTANT)
    Q_PROPERTY(QList <CurrencyEnum> cashList READ cashList NOTIFY cashListChanged)
public:
    Subject(QString title, SubjectId id, QObject *parent = nullptr);
    virtual QString uid() const final;
    virtual AFlib::SubjectType subjectType() const;
    virtual QList <CurrencyEnum> cashList() const final;

public slots:
    virtual void setUid(QString uid) final;

    void addToCashList(CurrencyEnum cashList);

signals:
    void uidChanged(QString uid);
    void cashListChanged(QList <CurrencyEnum> cashList);

private:
    QString m_uid;
    AFlib::SubjectType m_subjectType;
    QList <CurrencyEnum> m_cashList;
};
}
