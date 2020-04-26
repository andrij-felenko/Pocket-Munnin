#ifndef TRINNPLUGIN_H
#define TRINNPLUGIN_H

#include <AFquick/AfGuiPlugin>
#include <QtGui/QGuiApplication>

namespace Trinn {
    class Plugin;
    typedef QSharedPointer <Plugin> PluginPtr;
}

class Trinn::Plugin final : public AFquick::GuiPlugin
{
    Q_OBJECT
public:
    Plugin(QObject* parent = qApp);
    virtual ~Plugin() = default;

    virtual QString icon() const override;

    QUrl qmlUrl() const override;
    void initialize() override;
};

typedef Trinn::PluginPtr TrinnPluginPtr;

#endif // TRINNPLUGIN_H
