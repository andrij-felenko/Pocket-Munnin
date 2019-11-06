#pragma once
#include "type/base.h"

namespace Trinn {
class Subject : public Base
{
    Q_OBJECT
    Q_PROPERTY(QString uid READ uid WRITE setUid NOTIFY uidChanged)
    Q_PROPERTY(SubjectType subjectType READ subjectType CONSTANT)
    Q_PROPERTY(QList <Currency> cashList READ cashList NOTIFY cashListChanged)
public:
    Subject(QString title, Id id, QObject *parent = nullptr);
    virtual QString uid() const final;
    virtual SubjectType subjectType() const;
    virtual QList <Currency> cashList() const final;

public slots:
    virtual void setUid(QString uid) final;

    void addToCashList(Currency cashList);

signals:
    void uidChanged(QString uid);
    void cashListChanged(QList <Currency> cashList);

private:
    QString m_uid;
    SubjectType m_subjectType;
    QList <Currency> m_cashList;
};
}
