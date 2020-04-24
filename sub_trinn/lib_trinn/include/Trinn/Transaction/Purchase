#pragma once
#include <QtCore/QDateTime>
#include "baseTransaction.h"

namespace Trinn {
class Spend : public BaseTransaction
{
    Q_OBJECT
//    Q_PROPERTY(uint project  READ project  WRITE setProject  NOTIFY projectChanged)
    Q_PROPERTY(uint category READ category WRITE setCategory NOTIFY categoryChanged)
    Q_PROPERTY(quint64 merchant READ merchant WRITE setMerchant NOTIFY merchantChanged)
public:
    explicit Spend(QString title, uint user, uint id, QObject *parent = nullptr);
    virtual ~Spend() override = default;

//    virtual uint project()  const final;
    virtual uint    category() const final;
    virtual quint64 merchant() const final;

public slots:
//    void setProject(uint project);
    void setCategory(uint category);
    void setMerchant(quint64 sender);

signals:
//    void projectChanged(uint project);
    void categoryChanged(uint category);
    void merchantChanged(quint64 sender);

protected:
    Spend(QString title, SubjectId id, QObject* parent = nullptr);
//    uint m_project;
    uint m_category = 0;
};
}
