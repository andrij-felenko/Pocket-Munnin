#ifndef TRINNBASE
#define TRINNBASE

#include <QtCore/QObject>
#include <QtCore/QDateTime>
#include "lib_baseAF/id.h"
#include "trinnEnum.h"

namespace Trinn { class Base; }

class Trinn::Base : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QDateTime lastUpdate READ lastUpdate NOTIFY lastUpdateChanged)
public:
    Base(QString title, quint16 id, QObject* parent = nullptr);
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

#endif //TRINNBASE
