#include "subject/category.h"
#include "trinnStorage.h"

Trinn::subject::Category::Category(QObject *parent)
    : AFIdObjectTemplate(pluginId, typeToInt(Type::Category), parent)
{
    //
}

Trinn::subject::Category::Category(AFIdObjectPtr ptr, QObject *parent)
    : AFIdObjectTemplate(ptr, parent)
{
    //
}

void Trinn::subject::Category::addSubCategory(CategoryPtr ptr)
{
    for (auto it : m_subCategoryList)
        if (it->afObject()->object_b() == m_ptr->object_b())
            return;

    m_subCategoryList.push_back(ptr);
}
