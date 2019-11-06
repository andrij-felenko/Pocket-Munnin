#include "login/loginDatas.h"
#include <QtCore/QCryptographicHash>

void Trinn::LoginDatas::readFromDB()
{
    //
}

void Trinn::LoginDatas::updateFromServer(QHash <QString, QString> data)
{
    for (auto it = data.begin(); it != data.end(); ++it)
        m_hash.insert(it.key(), it.value());
    emit dataFromServerUpdates();
}

QStringList Trinn::LoginDatas::getLoginList() const
{
    return m_hash.keys();
}
