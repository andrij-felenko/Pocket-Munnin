#pragma once
#include "base.h"
#include <QtCore/QSharedPointer>

namespace Trinn {
class Category : public Base {
public:
    explicit Category(QString title, uint user, uint category, QObject* parent = nullptr);
    Category(QString title, uint user, uint category, uint sub, QObject* parent = nullptr);

    virtual uint subCategoryId() const final; // 0 -  7 bites
    virtual uint categoryId()    const final; // 8 - 21 bites

    static QSharedPointer <Category> create(QString title, uint user, uint category, QObject* parent = nullptr);
    static QSharedPointer <Category> create(QString title, uint user, uint category, uint sub, QObject* parent = nullptr);
};
}
