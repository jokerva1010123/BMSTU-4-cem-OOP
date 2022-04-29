//
//		����� �����
//
#include "stdafx.h"

#include "elevator.h"
#include "exceptions.h"

cElevator::cElevator(int num) : cBaseObject()
{
	state = LiftClosed;
	direction = LiftIdling;
	floorCur = 0;
	floorCount = num;
	floors = new bool [num];
	for (int i=0; i<num; i++)
		floors[i] = false;
}
cElevator::~cElevator()
{
	if (floors)
		delete [] floors;
}


//����������� ��������� ����� �� ������
void cElevator::Refresh()
{
	if (!display)
	{
		cENotLinked e;
		throw e;
	}

	Label^ lbl = (Label^) display;
	switch (state)
	{
	case LiftClosed:
		{
			lbl->Text = "Idling, closed"; break;
		}
	case LiftOpen:
		{
			lbl->Text = "Idling, open"; break;
		}
	case LiftMoving:
		{
			if (direction == LiftUp)
				lbl->Text = "Moving (upwards)";
			else
				lbl->Text = "Moving (downwards)";
			break;
		}
	case LiftOpening:
		{
			lbl->Text = "Opening doors"; break;
		}
	case LiftClosing:
		{
			lbl->Text = "Closing doors"; break;
		}
	default:
		{
			cEUnknownState e;
			throw e;
		}
	}
}


//��������, ���� �� ����� ����-�� �����
bool cElevator::LeftAbove() //������
{
	for (int i=floorCur+1; i<floorCount; i++)
		if (floors[i])
			return true;
	return false;
}
bool cElevator::LeftBelow() //����
{
	for (int i=floorCur-1; i>=0; i--)
		if (floors[i])
			return true;
	return false;
}

//--------------������� �� �������-------------------

//����� ����� �� ��������� ����
void cElevator::OnCall(cBaseObject^ source)
{
	cButton^ btn = (cButton^) source;
	int at_floor = btn->floor;

	if (at_floor >= floorCount)
		at_floor = floorCount-1;
	if (at_floor < 0)
		at_floor = 0;

	if (at_floor == floorCur && state == LiftClosed)
		InvokeStop();
	else
		floors[at_floor] = btn->IsPressed;
}

//����� ����� �������� �����������
void cElevator::OnDoorOpen(cBaseObject^ source)
{
	state = LiftOpening;
	ticker = 0;
	Refresh();
}

//����� ����� ����������� �����������
void cElevator::OnDoorOpenFinish(cBaseObject^ source)
{
	state = LiftOpen;
	ticker = 0;
	Refresh();
}

//����� ����� �������� �����������
void cElevator::OnDoorClose(cBaseObject^ source)
{
	state = LiftClosing;
	ticker = 0;
	Refresh();
}

//����� ����� ����������� �����������
void cElevator::OnDoorCloseFinish(cBaseObject^ source)
{
	state = LiftClosed;
	ticker = 0;
	Refresh();
}

//------------------�������-------------------------

//�������� �� �����
void cElevator::InvokeFloorPass()
{
	FloorPass(this);

	//���� �� ������� ����� ���� ������ ������������, �� �������� ��������� �����
	if (floors[floorCur])
	{
		InvokeStop();
	}
}

//������������
void cElevator::InvokeStop()
{
	Stop(this);
	ticker = 0;
	floors[floorCur] = false;
}

//����������� �������, ���������� �� �������� �����
void cElevator::Think()
{
	ticker++; //�� ��� �������� �������������
	if (ticker == TIME_MAX)
		ticker = 0;

	//���� ���� �����, � ������ ���������, �� ��������� ���
	if (state == LiftClosed && direction != LiftIdling)
	{
		state = LiftMoving;
		ticker = 0;
	}

	//���� ���� ��������, �� ���������� ��� �� ������, �������� ���������
	if (state == LiftMoving && ticker >= TIME_ON_PASS)
	{
		ticker = 0;
		if (direction == LiftUp)
			floorCur++;
		else
			floorCur--;

		InvokeFloorPass();
	}


	//�������������� ����������� �������� �����
	bool LB = LeftBelow();
	bool LA = LeftAbove();
	switch (direction)
	{
	case LiftIdling:
		{
			if (LB)
				direction = LiftDown;
			else if (LA)
				direction = LiftUp;
			break;
		}
	case LiftUp:
		{
			if (!LA && LB)
				direction = LiftDown;
			break;
		}
	case LiftDown:
		{
			if (LA && !LB)
				direction = LiftUp;
			break;
		}
	}
	if (direction != LiftIdling && !LB && !LA)
		direction = LiftIdling;

	Refresh();
}