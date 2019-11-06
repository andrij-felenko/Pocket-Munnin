#ifndef LISTTEMPLATE_H
#define LISTTEMPLATE_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QSharedPointer>

namespace Trinn {
template <typename T>
class ListTemplate : QList <QSharedPointer<T>>
{
public:
    explicit ListTemplate() { /* */ }

    void createOne(QString title)
    {
        this->push_back(QSharedPointer<T>::create(lastId(), title, this));
    }

    bool removeOne(int id)
    {
        for (auto it = this->begin(); it != this->end(); ++it)
            if (it->id() == id){
                this->removeOne(it);
                return true;
            }
        return false;
    }

    void loadFromData()
    {
        //
    }

    void saveToData()
    {
        //
    }

private:
    int lastId() const
    {
        int last = -1;
        for (auto it = this->begin(); it != this->end(); ++it)
            if (it->id() > last)
                last = it->id();
        return last;
    }
};
}

#endif // LISTTEMPLATE_H
