#ifndef TRINNID_H
#define TRINNID_H

#include <QtCore/QtGlobal>
#include <QtCore/QString>
#include "trinnEnum.h"

namespace Trinn {
struct Id { // FIXME edit in c++20
    /// encrypt unsigned long long
    ///   60  58  56   52   48   44   40   36   32   28  26  24  22  20  16   12    8    4    0
    ///    |   |   |    |    |    |    |    |    |    |   |   |   |  |    |    |    |    |    |.
    /// bbbb b b  bb bbbb bbbb bbbb bbbb bbbb bbbb bbbb  bb  bb  bb bb bbbb bbbb bbbb bbbb bbbb
    /// |      |  |                                      |   |      |- ---- ---- ---- ---- ---|.
    /// |      |  |                                      |   |      lot id
    /// |      |  |                                      |   lot type
    /// |      |  |                                      type subject (0-user)
    /// |      |  |- ---- ---- ---- ---- ---- ---- ---|
    /// |      |  subject id
    /// |      is saved
    /// key

    Id();
    Id(uint subjectId);
    Id(uint subjectId, LotType lotType, uint lotId = 0);

    quint64 toUInt64() const;
    static uint unite(uint i...);
    static quint64 unite64(uint i...);
    static Id fromUInt64(quint64 data);

    quint64 crypt();

    bool isSaved() const;
    void save(uint newLot);
    void save(uint newSubject, uint newLot);

    uint subject() const;
    uint subjectId() const;
    SubjectType subjectType() const;

    uint lotId() const;
    LotType lotType() const;
    void setLotType(LotType type);

private:
    uint : 5; //key
    bool m_isSaved   :  1;
    uint m_subjectId : 32;
    uint m_lotType   :  4;

protected:
    uint m_lotId     : 22;
};
}

#endif // TRINNID_H
