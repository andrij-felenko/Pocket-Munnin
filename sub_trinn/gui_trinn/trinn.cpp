#include "trinn.h"
#include <TrinnLib>

Trinn::Plugin::Plugin(QObject *parent) : AFquick::GuiPlugin("Trinn", parent)
{
    Trinn::storage();
}

QString Trinn::Plugin::icon() const
{
    return "qrc:/icon/business/coins.svg";
}

QUrl Trinn::Plugin::qmlUrl() const
{
    return QUrl("qrc:/trinn/main/TrinnMain.qml");
}

void Trinn::Plugin::initialize()
{
    //
}
