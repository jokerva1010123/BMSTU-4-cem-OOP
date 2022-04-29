#include "elevator.h"
#include "timer.h"
#include "doors.h"

Elevator::Elevator(QObject *parent) :
    QObject(parent),
    currentFloor(0)
{
    doors = new Doors;
    QObject::connect(this, SIGNAL(openDoors()), doors, SLOT(open()), Qt::QueuedConnection);
    QObject::connect(doors, SIGNAL(closed()), this, SLOT(onDoorsClosed()), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(openingDoors()), doors, SLOT(opening()), Qt::QueuedConnection);
    QObject::connect(doors, SIGNAL(AreOpened()), this, SLOT(onDoorsOpened()), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(closingDoors()), doors, SLOT(closing()), Qt::QueuedConnection);
    QObject::connect(doors, SIGNAL(DoorsAreOpened()), this, SLOT(onDoorsClosing()), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(doorsClosed()), doors, SLOT(closeDoors()), Qt::QueuedConnection);
}

Elevator::~Elevator()
{
    delete doors;
}

void Elevator::goUp()
{
    Timer::msleep(1500);
    emit stop();
}

void Elevator::goDown()
{
    Timer::msleep(1500);
    emit stop();
}
void Elevator::onDoorsOpening()
{
    emit openingDoors();
}
void Elevator::onDoorsClosing()
{
    emit closingDoors();
}

void Elevator::onDoorsOpened()
{
    emit openDoors();
}

void Elevator::onDoorsClosed()
{
    emit doorsClosed();
}
