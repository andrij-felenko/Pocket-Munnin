#include "type/base.h"

Trinn::Base::Base(QString title, Id id, QObject *parent)
    : QObject(parent), Id(id), m_title(title)
{
    //
}

QString Trinn::Base::title() const
{
    return m_title;
}

QDateTime Trinn::Base::lastUpdate() const
{
    return m_lastUpdate;
}

void Trinn::Base::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
    lastTimeUpdate();
}

void Trinn::Base::lastTimeUpdate()
{
    m_lastUpdate = QDateTime::currentDateTime();
    emit lastUpdateChanged(m_lastUpdate);
}
