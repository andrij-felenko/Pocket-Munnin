#include "type/category.h"

using namespace Trinn;

Category::Category(QString title, uint user, uint category, uint sub, QObject *parent)
    : Base(title, Id(user, uint(LotType::Category), (category << 8) + sub), parent)
{
    //
}

Category::Category(QString title, uint user, uint category, QObject *parent)
    : Category(title, user, category, 0, parent)
{
    //
}

uint Category::categoryId() const
{
    return lotId() >> 8;
}

uint Category::subCategoryId() const
{
    return lotId() % 1 << 8;
}

QSharedPointer <Category> Category::create(QString title, uint user, uint category, QObject* parent)
{
    return Category::create(title, user, category, 0, parent);
}

QSharedPointer <Category> Category::create(QString title, uint user, uint category, uint sub, QObject* parent)
{
    return QSharedPointer <Category>::create(title, user, category, sub, parent);
}
