#pragma once

#include "base.h"
#include "button.h"


enum eLiftState {LiftClosed, LiftOpen, LiftMoving, LiftOpening, LiftClosing};
enum eLiftDir {LiftIdling, LiftUp, LiftDown};

//����� �����
ref class cElevator : public cBaseObject
{
public:
	cElevator(int num);
	~cElevator();

	//����������� ��������� ����� �� ������
	virtual void Refresh() override;

	//��������, ���� �� ����� ����-�� �����
	bool LeftAbove();
	bool LeftBelow();
	
	//--------------������� �� �������-------------------

	//����� ����� �� ��������� ����
	void OnCall(cBaseObject^ source);

	//����� ����� �������� �����������
	void OnDoorOpen(cBaseObject^ source);
	
	//����� ����� ����������� �����������
	void OnDoorOpenFinish(cBaseObject^ source);
	
	//����� ����� �������� �����������
	void OnDoorClose(cBaseObject^ source);

	//����� ����� ����������� �����������
	void OnDoorCloseFinish(cBaseObject^ source);

	//------------------�������-------------------------

	//�������� �� �����
	void InvokeFloorPass();

	//������������
	void InvokeStop();


	//����������� �������, ���������� �� �������� �����
	void Think();


	eLiftState state;	//��������� �����
	eLiftDir direction;	//����������� ��������
	int floorCur;		//������� ����
	int floorCount;		//���������� ������, �� ������� ����� ������ ����
	bool *floors;		//������ ������, �� ������� ���� ���������������
	int ticker;			//������� ������������ think, ������� "�������" ����� �� ���������� ��������.

	//������ ��������, ����������� �� �������
	event dEHandler^ Start;
	event dEHandler^ Stop;
	event dEHandler^ FloorPass;
	event dEHandler^ Opened;
	event dEHandler^ Closed;
};