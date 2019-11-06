#pragma once
#include <QtCore/QObject>
#include <QtCore/QHash>

namespace Trinn {
class LoginDatas : public QObject
{
    Q_OBJECT

    struct SingleLogin {
        QString login;
        QString password;
    };

public:
    explicit LoginDatas() = default;

    void readFromDB();
    void updateFromServer(QHash<QString, QString> data);
    QStringList getLoginList() const;

signals:
    void dataFromServerUpdates();

private:
    QHash <QString, QString> m_hash;
};
}
