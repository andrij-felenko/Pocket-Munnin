#include "trinn.h"

Trinn::Plugin::Plugin(QObject *parent) : AFquick::GuiPlugin("Trinn", parent)
{
    //
}

QString Trinn::Plugin::icon() const
{
//    return "qrc:/icon/af_base/af_logo.svg";
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
