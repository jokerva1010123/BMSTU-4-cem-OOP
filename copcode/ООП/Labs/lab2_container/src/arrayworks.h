#pragma once

#include "array.h"

class cTest
{
public:
	char c;
};

enum eArrType {TInt, TDouble, TClass};


void PrintArray(const _cArrayBase *arr, eArrType type);