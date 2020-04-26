#include "trinn.h"

Trinn::Plugin::Plugin(QObject *parent) : AFquick::GuiPlugin("Trinn", parent)
{
    //
}

QString Trinn::Plugin::icon() const
{
    //TODO rewrite
    return "iio";
}

QUrl Trinn::Plugin::qmlUrl() const
{
    return QUrl("qrc:/trinn/main/TrinnMain.qml");
}

void Trinn::Plugin::initialize()
{
    //
}
