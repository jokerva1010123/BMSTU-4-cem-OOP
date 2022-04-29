#pragma once

#include "base.h"

ref class cIndicator : public cBaseObject
{
public:
	cIndicator();

	virtual void Refresh() override;

	void OnElevatorPass(cBaseObject^ source);

	int floor;
};