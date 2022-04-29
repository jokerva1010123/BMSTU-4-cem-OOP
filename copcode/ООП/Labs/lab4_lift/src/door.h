#pragma once

#include "base.h"

enum eDoorState {DoorClosed, DoorOpen, DoorOpening, DoorClosing, DoorBlocked};

ref class cDoor : public cBaseObject
{
public:

	cDoor();

	virtual void Refresh() override;

	//����������� ����������������� ������
	void Block();

	//--------------������� �� �������-------------------

	//������� �� �������������� �� ����� ����
	void OnElevatorStop(cBaseObject^ source);

	//------------------�������-------------------------

	//������� �����
	void InvokeOpen();

	//��������� �������� ������
	void InvokeOpenFinish();

	//������� �����
	void InvokeClose();

	//��������� �������� ������
	void InvokeCloseFinish();


	//����������� �������, ���������� �� �������� �����
	void Think();

//private:
	eDoorState state;
	bool IsBlocked;
	int ticker;

	dEHandler^ Open;
	dEHandler^ OpenFinish;
	dEHandler^ Close;
	dEHandler^ CloseFinish;
	dEHandler^ Blocked;
};