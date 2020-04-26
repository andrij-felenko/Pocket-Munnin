#include "trinn.h"

Trinn::Plugin::Plugin(QObject *parent) : AFquick::GuiPlugin("Trinn", parent)
{
    //
}

QUrl Trinn::Plugin::qmlUrl() const
{
    return QUrl("qrc:/trinn/main/TrinnMain.qml");
}

void Trinn::Plugin::initialize()
{
    //
}
