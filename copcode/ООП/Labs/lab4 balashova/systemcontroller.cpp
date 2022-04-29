#include "systemcontroller.h"
#include "elevator.h"
#include "exeptions.h"

SystemController::SystemController(QObject *parent, int floor) :
    QObject(parent),
    nFloor(floor),
    currentFloor(0),
    upButtons(0),
    downButtons(0),
    currentCondition(WAIT)
{
    upButtons = new bool[nFloor];
    downButtons = new bool[nFloor];
    if ((!upButtons) || (!downButtons))
    {
        delete upButtons;
        delete downButtons;
        upButtons = NULL;
        downButtons = NULL;
    }
    for (int i = 0; i < nFloor; i++)
    {
        upButtons[i] = false;
        downButtons[i] = false;
    }
}

SystemController::~SystemController()
{
    delete []upButtons;
    delete []downButtons;
}

void SystemController::upPushed(int floorNumber)
{
    if ((floorNumber < 0) || (floorNumber >= nFloor))
        throw OutOfBounds();
    if (!upButtons[floorNumber])
    {
        upButtons[floorNumber] = true;
        if (currentCondition == WAIT)
            chooseCondition();
    }
}

void SystemController::downPushed(int floorNumber)
{
    if ((floorNumber < 0) || (floorNumber >= nFloor))
        throw OutOfBounds();
    if (!downButtons[floorNumber])
    {
        downButtons[floorNumber] = true;
        if(currentCondition == WAIT)
            chooseCondition();
    }
}

void SystemController::chooseCondition()
{
    bool flag = false;
    for (int i = currentFloor; i < nFloor; i++)
    {
        if ((upButtons[i]) || (downButtons[i]))
            flag = true;
    }
    if (flag)
    {
        currentCondition = MOVE_UP;
        nextCommand();
        return;
    }
    flag = false;
    for (int i = currentFloor; i >= 0 ; i--)
    {
        if ((upButtons[i]) || (downButtons[i]))
            flag = true;
    }
    if (flag)
    {
        currentCondition = MOVE_DOWN;
        nextCommand();
        return;
    }
    currentCondition = WAIT;
}

void SystemController::nextCommand()
{
    switch (currentCondition)
    {
        case MOVE_UP: {
                            movingUpCommand();
                            break;
                      }
        case MOVE_DOWN: {
                            movingDownCommand();
                            break;
                        }
        case WAIT: break;
        default: throw UnknownCondition();
    }
    emit floorChandged(currentFloor);
}

void SystemController::movingUpCommand()
{
    if (upButtons[currentFloor])
    {
        upButtons[currentFloor] = false;
        downButtons[currentFloor] = false;
        emit open();
        return;
    }
    bool flag = false;
    for (int i = currentFloor + 1; i < nFloor; ++i)
    {
        if ((upButtons[i]) || (downButtons[i]))
            flag = true;
    }
    if (flag)
    {
        currentFloor++;
        emit up();
        return;
    }
    if (downButtons[currentFloor])
    {
        upButtons[currentFloor] = false;
        downButtons[currentFloor] = false;
        emit open();
        return;
    }
    chooseCondition();
}

void SystemController::movingDownCommand()
{
    if(downButtons[currentFloor])
    {
        upButtons[currentFloor] = false;
        downButtons[currentFloor] = false;
        emit open();
        return;
    }

    bool flag = false;
    for (int i = currentFloor -1; i >=0; --i)
    {
        if(upButtons[i] || downButtons[i])
            flag = true;
    }

    if (flag)
    {
        currentFloor--;
        emit down();
        return;
    }
    if(upButtons[currentFloor])
    {
        upButtons[currentFloor] = false;
        downButtons[currentFloor] = false;
        emit open();
        return;
    }
    chooseCondition();
}

void SystemController::addLiftConnection(Elevator *lift)
{
    QObject::connect(this, SIGNAL(up()), lift, SLOT(goUp()), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(down()), lift, SLOT(goDown()), Qt::QueuedConnection);
    QObject::connect(lift, SIGNAL(stop()), this, SLOT(nextCommand()), Qt::QueuedConnection);
    QObject::connect(lift, SIGNAL(doorsClosed()), this, SLOT(nextCommand()), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(open()), lift, SLOT(onDoorsOpening()), Qt::QueuedConnection);
}



