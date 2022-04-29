
#pragma once

#include "base.h"

ref class cButton : public cBaseObject
{
public:
	cButton(int num);

	//����������� ��������� ������ �� ������
	virtual void Refresh() override;

	//--------------������� �� �������-------------------

	//������� �� �������������� �� ����� ����
	void OnElevatorStop(cBaseObject^ source);

	//------------------�������-------------------------

	//�������� ����������� � �������
	void InvokePress();


	int floor; //����, �� ������� ����������� ������
	bool IsPressed; //���� ���������

	event dEHandler^ Press;
};

/*
struct sButtonData : public sBaseData
{
	int floor;
	bool IsPressed;
};*/