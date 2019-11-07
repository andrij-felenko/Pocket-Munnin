#ifndef TRINNPLUGIN_H
#define TRINNPLUGIN_H

#include <QtCore/QtGlobal>
#include <QtCore/QString>
#include "trinnEnum.h"
#include "plugin.h"

namespace Trinn { class TrinnPlugin; }

class Trinn::TrinnPlugin : public AFlib::Plugin
{
    Q_OBJECT
public:
    TrinnPlugin(QObject* parent = nullptr);
    virtual ~TrinnPlugin() = default;
};

#endif // TRINNPLUGIN_H
