#include "doors.h"
#include "timer.h"

Doors::Doors(QObject *parent) :
    QObject(parent)
{
}

void Doors::open()
{
    Timer::msleep(1000);
    emit DoorsAreOpened();
}

void Doors::opening()
{
    Timer::msleep(1000);
    emit AreOpened();
}

void Doors::closing()
{
    Timer::msleep(1000);
    emit closed();
}
