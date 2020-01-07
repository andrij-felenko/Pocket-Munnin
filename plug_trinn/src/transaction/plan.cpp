#include "transaction/plan.h"

Trinn::Plan::Plan(QString title, SubjectId id, QObject* parent)
    : BaseTransaction(title, id, parent)
{
    //
}

Trinn::Plan::Plan(QString title, uint user, uint id, QObject *parent )
    : Plan(title, Id(user, uint(LotType::Transaction), Id::unite(2, 3, Ttype::Spend, 19, id)), parent)
{
    //
}

bool Trinn::Plan::archive() const
{
    return m_archive;
}

void Trinn::Plan::setArchive(bool archive)
{
    if (m_archive == archive)
        return;

    m_archive = archive;
    emit archiveChanged(m_archive);
    lastTimeUpdate();
}
