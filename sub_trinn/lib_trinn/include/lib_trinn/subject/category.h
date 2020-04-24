#ifndef TRINN_LIB_SUBJECT_CATEGORY_H
#define TRINN_LIB_SUBJECT_CATEGORY_H

#include <AFbaseLib>
#include <QtCore/QSharedPointer>

namespace Trinn::subject {
    class Category;
    typedef QSharedPointer <Category> CategoryPtr;
}

class Trinn::subject::Category : public QObject, public AFIdObject
{
    Q_OBJECT
public:
    explicit Category(QObject *parent = nullptr);
    Category(AFIdObjectPtr ptr,  QObject *parent = nullptr);
    Category(AFIdObject* object, QObject *parent = nullptr);
    virtual ~Category() = default;
};

typedef Trinn::subject::CategoryPtr TrinnCategoryPtr;

#endif //TRINN_LIB_SUBJECT_CATEGORY_H
