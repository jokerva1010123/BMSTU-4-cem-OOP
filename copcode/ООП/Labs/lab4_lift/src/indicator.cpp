//
//		Класс индикатора этажа лифта
//
#include "stdafx.h"

#include "indicator.h"
#include "elevator.h"

cIndicator::cIndicator()
{
	floor = 0;
}
void cIndicator::Refresh()
{
	Label^ lbl = (Label^) display;
	lbl->Text = String::Format("<{0}>", floor);
}

void cIndicator::OnElevatorPass(cBaseObject^ source)
{
	cElevator^ el = (cElevator^) source;
	floor = el->floorCur;
	Refresh();
}