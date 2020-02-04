#ifndef MONEYACCOUNTING_H
#define MONEYACCOUNTING_H

#include <QtQuick/QQuickItem>

#include "lib_baseAF/pluginMetadata.h"
#include "lib_baseAF/libHandler.h"
#include "lib_quickAF/pluginGui.h"
#include "dataHandler.h"

class MoneyAccounting : public AFlib::PluginGui
{
    Q_OBJECT
#ifdef _MODULE_
    Q_PLUGIN_METADATA(IID QuickAFlibPlugin_iid FILE "../metadata.json")
    Q_INTERFACES(AFlib::PluginQml)
#endif

public:
    explicit MoneyAccounting();
    ~MoneyAccounting() override = default;

    bool start() override;
    void stop() override;
    QUrl source() override;
    void initialize() override;
};

#endif // MONEYACCOUNTING_H
