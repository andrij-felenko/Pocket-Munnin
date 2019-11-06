#pragma once
#include <QtCore/QDateTime>
#include "magnet.h"

namespace Trinn {
class Income : public Magnet
{
    Q_OBJECT
public:
    explicit Income(QString title, uint user, uint id, QObject *parent = nullptr);
    virtual ~Income() = default;

protected:
    Income(QString title, Id id, QObject* parent = nullptr);
};
}
