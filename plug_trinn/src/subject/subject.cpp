#include "subject/subject.h"

Trinn::Subject::Subject(QString title, Id id, QObject* parent)
    : Base(title, id, parent)
{
    //
}

QString Trinn::Subject::uid() const
{
    return m_uid;
}

Trinn::SubjectType Trinn::Subject::subjectType() const
{
    return m_subjectType;
}

QList<Trinn::Currency> Trinn::Subject::cashList() const
{
    return m_cashList;
}

void Trinn::Subject::setUid(QString uid)
{
    if (m_uid == uid)
        return;

    m_uid = uid;
    emit uidChanged(m_uid);
}

void Trinn::Subject::addToCashList(Currency cashName)
{
    if (m_cashList.contains(cashName))
        return;

    m_cashList.push_back(cashName);
    emit cashListChanged(m_cashList);
}
