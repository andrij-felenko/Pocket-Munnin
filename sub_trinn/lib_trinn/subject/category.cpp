#include "subject/category.h"

Trinn::subject::Category::Category(QObject *parent) : QObject(parent)
{
    //
}

Trinn::subject::Category::Category(AFIdObjectPtr ptr, QObject *parent)
    : QObject(parent), AFIdObject(ptr.data())
{
    //
}

Trinn::subject::Category::Category(AFIdObject *object, QObject *parent)
    : QObject(parent), AFIdObject(object)
{
    //
}

void Trinn::subject::Category::addSubCategory(CategoryPtr ptr)
{
    for (auto it : m_subCategoryList)
        if (it->object_b() == ptr->object_b())
            return;

    m_subCategoryList.push_back(ptr);
}
