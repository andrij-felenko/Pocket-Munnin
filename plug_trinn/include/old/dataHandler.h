#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QtCore/QObject>
#include <QtQml/QQmlListProperty>
#include "listTemplate.h"
//#include "card.h"
//#include "subject.h"
//#include "transaction.h"

namespace Trinn {
class DataHandler : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QQmlListProperty <SingleCard> cards READ cards)
//    Q_PROPERTY(QQmlListProperty <SingleGroup> groupsUser READ groupsUser)
//    Q_PROPERTY(QQmlListProperty <SingleGroup> groupsObject READ groupsObject)
//    Q_PROPERTY(QQmlListProperty <SingleOperate> operates READ operates)

public:
    explicit DataHandler(QObject *parent = nullptr);

    static const DataHandler* dataHandler();
    static void init();

//    virtual QQmlListProperty <SingleCard>    cards()        const final { return m_cards; }
//    virtual QQmlListProperty <Subject>   groupsUser()   const final { return m_groupsUser; }
//    virtual QQmlListProperty <Subject>   groupsObject() const final { return m_groupsObject; }
//    virtual QQmlListProperty <Transaction> operates()     const final { return m_operates; }

signals:

public slots:

private:
    static DataHandler* m_dataHandler;
//    QQmlListProperty <SingleCard> m_cards;
//    QQmlListProperty <Subject> m_groupsUser;
//    QQmlListProperty <Subject> m_groupsObject;
//    QQmlListProperty <Transaction> m_operates;
};
}

#endif // DATAHANDLER_H
