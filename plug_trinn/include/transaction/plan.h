#ifndef TRINNPLAN
#define TRINNPLAN

#include "baseTransaction.h"

namespace Trinn {
class Plan : public BaseTransaction
{
    Q_OBJECT
    // periodical values
    Q_PROPERTY(bool archive READ archive WRITE setArchive NOTIFY archiveChanged)
public:
    explicit Plan(QString title, uint user, uint id, QObject* parent = nullptr);
    virtual ~Plan() override = default;

    virtual bool archive() const final;

public slots:
    void setArchive(bool archive);

signals:
    void archiveChanged(bool archive);

protected:
    Plan(QString title, SubjectId id, QObject* parent = nullptr);
    bool m_archive = false;
};
}

#endif //TRINNPLAN


