//
//		Преобразования массивов в строки
//
#include "stdafx.h"

#include <stdio.h>

#include "arrayworks.h"
#include "array.h"


cArray<int> IntsInit(int num)
{
	cArray<int> arr(num);
	for (int i=0; i<num; i++)
		arr[i] = i;
	return arr;
}
cArray<double> DoubleInit(int num)
{
	cArray<double> arr(num);
	for (int i=0; i<num; i++)
		arr[i] = 1 + 0.5*i;
	return arr;
}


void PrintArray(const _cArrayBase *arr, eArrType type)
{
	if (arr->GetSize()<=0) 	printf("<empty>\n");

	printf("array(%d, ", arr->GetSize());

	switch (type)
	{
	case TInt:
		{
			printf("int):  ");
			const cArray<int> *pArr = static_cast <const cArray<int>*> (arr);
			for (int i=0; i<arr->GetSize(); i++)
				printf("%d ", (*pArr)[i]);
			break;
		}
	case TDouble:
		{
			printf("double):  ");
			const cArray<double> *pArr = static_cast <const cArray<double>*> (arr);
			for (int i=0; i<arr->GetSize(); i++)
				printf("%.2lf ", (*pArr)[i]);
			break;
		}
	case TClass:
		{
			printf("class):  ");
			const cArray<cTest*> *pArr = static_cast <const cArray<cTest*>*> (arr);
			for (int i=0; i<arr->GetSize(); i++)
				printf("%c ", (*pArr)[i]->c);
			break;
		}
	default:
		{
			printf("UNKNOWN)");
			break;
		}
	}
	printf("\n");
}
