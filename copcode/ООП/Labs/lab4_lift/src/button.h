
#pragma once

#include "base.h"

ref class cButton : public cBaseObject
{
public:
	cButton(int num);

	//отображение состояния кнопки на батоне
	virtual void Refresh() override;

	//--------------реакции на события-------------------

	//реакция на остановившийся на этаже лифт
	void OnElevatorStop(cBaseObject^ source);

	//------------------события-------------------------

	//рассылка уведомлений о нажатии
	void InvokePress();


	int floor; //этаж, на котором расположена кнопка
	bool IsPressed; //флаг нажатости

	event dEHandler^ Press;
};

/*
struct sButtonData : public sBaseData
{
	int floor;
	bool IsPressed;
};*/