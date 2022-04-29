#pragma once

#include <QObject>

class Doors;

class Elevator : public QObject
{
    Q_OBJECT

public:
    explicit Elevator(QObject *parent = 0);
    ~Elevator();
    
signals:
    void stop();
    void doorsClosed();
    void openDoors();
    void openingDoors();
    void closingDoors();

public slots:
    void goUp();
    void goDown();
    void onDoorsOpened();
    void onDoorsClosed();
    void onDoorsOpening();
    void onDoorsClosing();
    void onDoorsClose();

private:
    int currentFloor;
    Doors* doors;
};

