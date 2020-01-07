#include "transaction/income.h"

Trinn::Income::Income(QString title, SubjectId id, QObject *parent )
    : Magnet(title, id, parent)
{
    //
}

Trinn::Income::Income(QString title, uint user, uint id, QObject *parent )
    : Income(title, Id(user, uint(LotType::Transaction), Id::unite(2, 3, Ttype::Income, 19, id)), parent)
{
    //
}
