#ifndef CATEGORY_H
#define CATEGORY_H

#include <QtCore/QObject>

namespace Trinn {
    QByteArray crypt(QByteArray array);
    QByteArray encrypt(QByteArray array);

    void toCrypt(uint &data);
    void toCrypt(quint64 &data);
    void toEncrypt(uint &data);
    void toEncrypt(quint64 &data);
    uint getCrypt(uint data);
    uint getEncrypt(uint data);
    quint64 getCrypt(quint64 data);
    quint64 getEncrypt(quint64 data);
}

#endif // SINGLECARD_H
