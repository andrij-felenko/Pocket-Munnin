#include "id.h"
#include "crypt.h"
#include <bitset>
#include <cstdarg>

uint codeString(QString str, uint size);

Trinn::Id::Id() : Id(uint(0))
{
    //
}

Trinn::Id::Id(uint subjectId) : Id(subjectId, LotType::None, 0)
{
    //
}

Trinn::Id::Id(uint subjectId, LotType lotType, uint lotId)
    : m_isSaved(false),
    m_subjectId(subjectId),
    m_lotType(uint(lotType)),
    m_lotId(lotId)
{
    //
}

quint64 Trinn::Id::toUInt64() const
{
    return unite(4, 1, m_isSaved, 32, m_subjectId, 4, uint(m_lotType), 22, m_lotId);
}

uint Trinn::Id::unite(uint i...)
{
    return uint(unite64(i));
}

quint64 Trinn::Id::unite64(uint i...)
{
    va_list args;
    va_start(args, i);
    quint64 data = va_arg(args, uint);

    while (i != 0){
        uint shift = va_arg(args, uint);
        data += va_arg(args, uint) % (1 << shift);
        --i;
        if (i == 0)
            break;
        data <<= shift;
    }
    return data;
}

Trinn::Id Trinn::Id::fromUInt64(quint64 data)
{
    // test is it encrypt, key size  = 5
    if (data << 59 != 0)
        Trinn::toEncrypt(data);

    Id id;
    id.m_lotId     = data << 42 >> 42;    data >>= 22;
    id.m_lotType   = data << 60 >> 60;    data >>=  4;
    id.m_subjectId = data << 32 >> 32;    data >>= 32;
    id.m_isSaved   = data;
    return id;
}

quint64 Trinn::Id::crypt()
{
    return Trinn::getCrypt(toUInt64());
}

bool Trinn::Id::isSaved() const
{
    return m_isSaved;
}

void Trinn::Id::save(uint newLot)
{
    m_lotId = newLot;
    m_isSaved = true;
}

void Trinn::Id::save(uint newSubject, uint newLot)
{
    m_subjectId = newSubject;
    m_lotId = newLot;
    m_isSaved = true;
}

uint Trinn::Id::subject() const
{
    return m_subjectId;
}

uint Trinn::Id::subjectId() const
{
    return m_subjectId >> 2;
}

Trinn::SubjectType Trinn::Id::subjectType() const
{
    uint subj = m_subjectId % 4;
    if (subj == 3)
        return SubjectType::Group;
    return SubjectType(subj);
}

uint Trinn::Id::lotId() const
{
    return m_lotId;
}

Trinn::LotType Trinn::Id::lotType() const
{
    return LotType(m_lotType);
}

void Trinn::Id::setLotType(Trinn::LotType type)
{
    m_lotType = uint(type);
}

uint codeString(QString str, uint size)
{
    uint coef = 1;
    uint data = 0;
    uint min = 255;
    for (auto it : str)
        if (uint(it.toLatin1()) < min)
            min = uint(it.toLatin1());
    min++;

    for (auto it : str){
        data += (uint(it.toLatin1()) - min) * coef;
        coef *= 16;
    }
    return data %= uint(1 << size);
}
