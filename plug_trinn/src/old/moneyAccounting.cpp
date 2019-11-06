#include <QtCore>
#include <QtQml/QQmlEngine>

#include "system.h"
#include "old/moneyAccounting.h"

MoneyAccounting::MoneyAccounting() : AFlib::PluginGui()
{
//    qmlRegisterPlugin("qrc:/MQ", 1, 1);
}

bool MoneyAccounting::start()
{
    return true;
}

void MoneyAccounting::stop()
{
    //
}

QUrl MoneyAccounting::source()
{
    QDir dir(":");
    qDebug() << "MA" << dir << dir.entryList(QDir::Filter::AllEntries);
    dir.cd("LibDynamic");
    qDebug() << dir << dir.entryList(QDir::Filter::AllEntries);
    return QUrl("qrc:/Plugins/MoneyAccounting/qml/MoneyAccountingView.qml");
}

void MoneyAccounting::initialize()
{
    Trinn::DataHandler::init();
}
