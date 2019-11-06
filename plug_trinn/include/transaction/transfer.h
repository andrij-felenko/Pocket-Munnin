#pragma once
#include <QtCore/QDateTime>
#include "baseTransaction.h"

namespace Trinn {
class Transfer : public BaseTransaction
{
    Q_OBJECT
//    Q_PROPERTY(uint project READ project WRITE setProject NOTIFY projectChanged)
    Q_PROPERTY(Tconfirm confirm READ confirm WRITE setConfirm NOTIFY confirmChanged)
public:
    explicit Transfer(QString title, uint user, uint id, QObject *parent = nullptr);
    virtual ~Transfer() = default;

//    virtual uint project() const final { return m_project; }
    virtual Tconfirm confirm() const final;

public slots:
//    void setProject(uint project);
    void setConfirm(Tconfirm confirm);

signals:
//    void projectChanged(uint project);
    void confirmChanged(Tconfirm confirm);

private:
    Transfer(QString title, Id id, QObject* parent = nullptr);
//    uint m_project;
    Tconfirm m_confirm;
};
}
