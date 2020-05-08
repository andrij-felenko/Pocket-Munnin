#ifndef TRINN_LIB_SUBJECT_CATEGORY_H
#define TRINN_LIB_SUBJECT_CATEGORY_H

#include <AFbaseLib>
#include <QtCore/QSharedPointer>

namespace Trinn::subject {
    class Category;
    typedef QSharedPointer <Category> CategoryPtr;
}

class Trinn::subject::Category : public AFIdObjectTemplate
{
    Q_OBJECT
public:
    explicit Category(QObject *parent = nullptr);
    Category(AFIdObjectPtr ptr,  QObject *parent = nullptr);
    virtual ~Category() = default;

    void addSubCategory(CategoryPtr ptr);

private:
    QList <CategoryPtr> m_subCategoryList;
};

typedef Trinn::subject::CategoryPtr TrinnCategoryPtr;

#endif //TRINN_LIB_SUBJECT_CATEGORY_H
