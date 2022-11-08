#ifndef CONTROLLERSIGNAL_H
#define CONTROLLERSIGNAL_H

#include <QObject>
#include <QVariant>

class controllerSignal : public QObject
{
    Q_OBJECT
public:
    explicit controllerSignal(QObject *parent = 0);

signals:

public slots:
    void clickSlot();
};

#endif // CONTROLLERSIGNAL_H
