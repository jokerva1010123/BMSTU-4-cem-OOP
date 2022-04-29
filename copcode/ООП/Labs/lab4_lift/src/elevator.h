#pragma once

#include "base.h"
#include "button.h"


enum eLiftState {LiftClosed, LiftOpen, LiftMoving, LiftOpening, LiftClosing};
enum eLiftDir {LiftIdling, LiftUp, LiftDown};

//класс лифта
ref class cElevator : public cBaseObject
{
public:
	cElevator(int num);
	~cElevator();

	//отображение состояния лифта на лейбле
	virtual void Refresh() override;

	//проверка, надо ли лифту куда-то ехать
	bool LeftAbove();
	bool LeftBelow();
	
	//--------------реакции на события-------------------

	//вызов лифта на указанный этаж
	void OnCall(cBaseObject^ source);

	//двери лифта начинают открываться
	void OnDoorOpen(cBaseObject^ source);
	
	//двери лифта заканчивают открываться
	void OnDoorOpenFinish(cBaseObject^ source);
	
	//двери лифта начинают закрываться
	void OnDoorClose(cBaseObject^ source);

	//двери лифта заканчивают закрываться
	void OnDoorCloseFinish(cBaseObject^ source);

	//------------------события-------------------------

	//пройтись по этажу
	void InvokeFloorPass();

	//остановиться
	void InvokeStop();


	//управляющая функция, отвечающая за действия лифта
	void Think();


	eLiftState state;	//состояние лифта
	eLiftDir direction;	//направление движения
	int floorCur;		//текущий этаж
	int floorCount;		//количество этажей, по которым может ездить лифт
	bool *floors;		//массив этажей, на которых надо останавливаться
	int ticker;			//счётчик срабатываний think, сколько "времени" нужно на совершение действия.

	//списки объектов, подписанных на события
	event dEHandler^ Start;
	event dEHandler^ Stop;
	event dEHandler^ FloorPass;
	event dEHandler^ Opened;
	event dEHandler^ Closed;
};