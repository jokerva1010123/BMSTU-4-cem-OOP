#pragma once

#include <QObject>
class Elevator;

typedef enum {WAIT, MOVE_UP, MOVE_DOWN} LiftCondition;

class SystemController : public QObject
{
    Q_OBJECT
private:
    int nFloor;
    int currentFloor;
    bool *upButtons;
    bool *downButtons;
    LiftCondition currentCondition;

public:
    explicit SystemController(QObject *parent = 0, int floor = 0);
    ~SystemController();   
    void addLiftConnection(Elevator* lift);

    void upPushed(int floorNumber);
    void downPushed(int floorNumber);

signals:
    void up();
    void down();
    void open();
    void floorChandged(int floorNumber);

public slots:
    void nextCommand();
    void movingUpCommand();
    void movingDownCommand();
    void chooseCondition();
};
