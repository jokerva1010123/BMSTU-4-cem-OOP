#pragma once

#include "base.h"

enum eDoorState {DoorClosed, DoorOpen, DoorOpening, DoorClosing, DoorBlocked};

ref class cDoor : public cBaseObject
{
public:

	cDoor();

	virtual void Refresh() override;

	//переключить заблокированность дверей
	void Block();

	//--------------реакции на событи€-------------------

	//реакци€ на остановившийс€ на этаже лифт
	void OnElevatorStop(cBaseObject^ source);

	//------------------событи€-------------------------

	//открыть двери
	void InvokeOpen();

	//завершить открытие дверей
	void InvokeOpenFinish();

	//закрыть двери
	void InvokeClose();

	//завершить закрытие дверей
	void InvokeCloseFinish();


	//управл€юща€ функци€, отвечающа€ за действи€ двери
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