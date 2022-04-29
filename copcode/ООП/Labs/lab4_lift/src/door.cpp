//
//		����� ������ �����
//
#include "stdafx.h"

#include "door.h"
#include "exceptions.h"

cDoor::cDoor()
{
	state = DoorClosed;
	ticker = 0;
	IsBlocked = false;
}

void cDoor::Refresh()
{
	if (!display)
	{
		cENotLinked e;
		throw e;
	}

	Label^ lbl = (Label^) display;
	if (IsBlocked)
		lbl->BackColor = System::Drawing::Color::PaleVioletRed;
	else
		lbl->BackColor = System::Drawing::Color::PaleGreen;
	switch (state)
	{
	case DoorClosed:
		{
			lbl->Text = "Closed"; break;
		}
	case DoorOpen:
		{
			lbl->Text = "Open"; break;
		}
	case DoorOpening:
		{
			lbl->Text = "opening..."; break;
		}
	case DoorClosing:
		{
			lbl->Text = "closing..."; break;
		}
	case DoorBlocked:
		{
			lbl->Text = "Blocked!"; break;
		}
	default:
		{
			cEUnknownState e;
			throw e;
		}
	}
}

//����������� ����������������� ������
void cDoor::Block()
{
	IsBlocked = !IsBlocked;
	Refresh();
}

//--------------������� �� �������-------------------

//������� �� �������������� �� ����� ����
void cDoor::OnElevatorStop(cBaseObject^ source)
{
	InvokeOpen();
}

//------------------�������-------------------------

//������� �����
void cDoor::InvokeOpen()
{
	ticker = 0;
	state = DoorOpening;
	Open(this);
	Refresh();
}

//��������� �������� ������
void cDoor::InvokeOpenFinish()
{
	ticker = 0;
	state = DoorOpen;
	OpenFinish(this);
	Refresh();
}

//������� �����
void cDoor::InvokeClose()
{
	ticker = 0;
	state = DoorClosing;
	Close(this);
	Refresh();
}

//��������� �������� ������
void cDoor::InvokeCloseFinish()
{
	ticker = 0;
	state = DoorClosed;
	CloseFinish(this);
	Refresh();
}


//����������� �������, ���������� �� �������� �����
void cDoor::Think()
{
	ticker++; //�� ��� �������� �������������
	if (ticker == TIME_MAX)
		ticker = 0;

	if (state == DoorOpening && ticker >= TIME_ON_OPEN)
	{
		if (!IsBlocked)
			InvokeOpenFinish();
	}

	if (state == DoorOpen && ticker >= TIME_ON_IDLE)
	{
		InvokeClose();
	}
	
	if (state == DoorClosing && ticker >= TIME_ON_OPEN)
	{
		if (!IsBlocked)
			InvokeCloseFinish();
	}
}