#pragma once
#include <QtCore/QObject>
#include "id.h"

namespace Trinn { class Me; }

class Trinn::Me : public QObject, public AFlib::AccountId
{
public:
    explicit Me() = default;
    virtual ~Me() override = default;
};
