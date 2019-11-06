#ifndef TRINNBASE
#define TRINNBASE

#include <QtCore/QObject>
#include <QtCore/QDateTime>
#include "id.h"

namespace Trinn {
class Base : public QObject, public Id
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QDateTime lastUpdate READ lastUpdate NOTIFY lastUpdateChanged)
public:
    Base(QString title, Id id, QObject* parent = nullptr);
    virtual ~Base() = default;

    virtual QString title() const final;
    virtual QDateTime lastUpdate() const final;

public slots:
    virtual void setTitle(QString title) final;

protected slots:
    virtual void lastTimeUpdate() final;

signals:
    void titleChanged(QString title);
    void lastUpdateChanged(QDateTime lastUpdate);

private:
    QString m_title;
    QDateTime m_lastUpdate;
};
}

#endif //TRINNBASE
