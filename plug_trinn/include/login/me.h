#pragma once
#include <QtCore/QObject>
#include "id.h"

namespace Trinn {
class Me : public QObject, public Id
{
public:
    explicit Me() = default;
    virtual ~Me() override = default;
};
}

