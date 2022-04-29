//
//		Класс кнопки
//
#include "stdafx.h"

#include "button.h"
#include "elevator.h"
#include "exceptions.h"

cButton::cButton(int num)
{
	floor = num;
	IsPressed = false;
}

void cButton::Refresh()
{
	if (!display)
	{
		cENotLinked e;
		throw e;
	}

	Button^ btn = (Button^) display;
	if (IsPressed)
		btn->Text = String::Format("{0}  [V]", floor);
	else
		btn->Text = String::Format("{0}  [_]", floor);
}


//рассылка уведомлений о нажатии
void cButton::InvokePress()
{
	IsPressed = !IsPressed;
	Press(this);
	Refresh();
}


//private:

void cButton::OnElevatorStop(cBaseObject^ source)
{
	cElevator^ el = (cElevator^) source;
	if (el->floorCur == floor && IsPressed)
	{
		IsPressed = false;
		Refresh();
	}
}