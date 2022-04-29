#pragma once

#include "elevator.h"
#include "button.h"
#include "indicator.h"
#include "door.h"


#define FLOORS_NUMBER 4


ref class cLiftSystem
{
public:
	cElevator^ elevator;
	cIndicator^ indicator;
	cDoor^ door;
	cButton ^F0, ^F1, ^F2, ^F3;

	cLiftSystem()
	{
		//создаём объекты системы
		elevator = gcnew cElevator(FLOORS_NUMBER);
		door = gcnew cDoor();
		indicator = gcnew cIndicator();
		F0 = gcnew cButton(0);
		F1 = gcnew cButton(1);
		F2 = gcnew cButton(2);
		F3 = gcnew cButton(3);

		//привязываем к объектам события
		LinkButtonToElevator(F0, elevator);
		LinkButtonToElevator(F1, elevator);
		LinkButtonToElevator(F2, elevator);
		LinkButtonToElevator(F3, elevator);
		LinkDoorToElevator(door, elevator);
		LinkIndicatorToElevator(indicator, elevator);

	}
	~cLiftSystem()
	{
		delete elevator, door;
		delete F0,F1,F2,F3;
	}

	void LinkButtonToElevator(cButton^ btn, cElevator^ el)
	{
		btn->Press += gcnew dEHandler(el, &cElevator::OnCall);
		el->Stop += gcnew dEHandler(btn, &cButton::OnElevatorStop);
	}
	void LinkDoorToElevator(cDoor^ d, cElevator^ el)
	{
		d->Open += gcnew dEHandler(el, &cElevator::OnDoorOpen);
		d->Close += gcnew dEHandler(el, &cElevator::OnDoorClose);
		d->OpenFinish += gcnew dEHandler(el, &cElevator::OnDoorOpenFinish);
		d->CloseFinish += gcnew dEHandler(el, &cElevator::OnDoorCloseFinish);
		el->Stop += gcnew dEHandler(door, &cDoor::OnElevatorStop);
	}
	void LinkIndicatorToElevator(cIndicator^ ind, cElevator^ el)
	{
		el->FloorPass += gcnew dEHandler(ind, &cIndicator::OnElevatorPass);
	}

	void Think()
	{
		elevator->Think();
		door->Think();
	}
	/*
	void OnButtonPress(cBaseObject^ source)
	{
		cButton^ btn = (cButton^) source;
		DEBUGPRINT("нажата кнопка этажа {0}", btn->floor);
		elevator->floors[btn->floor] = btn->IsPressed;
		elevator->Think();
	}
	void OnElevatorPass(cBaseObject^ source)
	{
		cElevator^ el = (cElevator^) source;
		DEBUGPRINT("элеватор поднялся на этаж {0}", el->floorCur);
	}*/
};
