#pragma once

#include <QObject>

class Doors : public QObject
{
    Q_OBJECT
public:
    explicit Doors(QObject *parent = 0);
    
signals:
    void closed();
    void AreOpened();
    void AreClosed();
    void DoorsAreOpened();

public slots:
    void open();
    void opening();
    void closeDoors();
    void closing();
};
