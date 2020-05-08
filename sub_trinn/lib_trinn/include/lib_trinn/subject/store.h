#ifndef TRINN_LIB_SUBJECT_STORE_H
#define TRINN_LIB_SUBJECT_STORE_H

#include <QtCore/QSharedPointer>
#include <AFbaseLib>

namespace Trinn::subject {
    class Store;
    typedef QSharedPointer <Store> StorePtr;
}

class Trinn::subject::Store : public AFIdObjectTemplate
{
public:
    explicit Store(QObject *parent = nullptr);
    Store(AFIdObjectPtr ptr,  QObject *parent = nullptr);
    virtual ~Store() = default;
};

typedef Trinn::subject::Store    TrinnStore;
typedef Trinn::subject::StorePtr TrinnStorePtr;

#endif //TRINN_LIB_SUBJECT_STORE_H
