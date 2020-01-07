#ifndef TRINNCARD
#define TRINNCARD

#include "subject.h"

namespace Trinn {
class BankCard : public Subject
{
    Q_OBJECT
public:
    BankCard(QString title, SubjectId id, QObject *parent = nullptr);
    virtual ~BankCard() = default;

private:
    QString m_uid;
};
}

#endif //TRINNCARD



