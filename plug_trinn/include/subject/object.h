#pragma once
#include "subject.h"

namespace Trinn {
class Object : public Subject
{
    Q_OBJECT
    Q_PROPERTY(QList <uint> bankCardIds READ bankCardIds NOTIFY bankCardIdsChanged)
public:
    Object() = default;
    QList <uint> bankCardIds() const;

signals:
    void bankCardIdsChanged(QList <uint> bankCardIds);

private:
    QList <uint> m_bankCardIds;
};
}
