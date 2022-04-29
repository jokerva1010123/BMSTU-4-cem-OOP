// src.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "array.h"
#include "arrayworks.h"
#include "my_exceptions.h"

#include <conio.h>
#include <stdio.h>

int main()
{
	try
	{
		const cArray<int> arr1(-5, 1,2,3,4,5);
		cArray<int> arr2 = arr1;
		cArray<int> arr3(3);
		arr3[0] = arr3[1] = arr3[50] = 0;

		printf("const arr1 = "); PrintArray(&arr1, TInt);
		printf("Arr2 = "); PrintArray(&arr2, TInt);
		printf("Arr3 = "); PrintArray(&arr3, TInt);

		puts("\nInserting arr3 into arr2 at #2 ...");
		printf("Arr2 = "); PrintArray(&cArray<int>::InsertArray(arr2, arr3, 2), TInt);

		puts("\nInserting '11' into arr2 at #4 ...");
		printf("Arr2 = "); PrintArray(&cArray<int>::InsertSingle(arr2, 11, 4), TInt);

		puts("\nDeleting #0 from arr2 ...");
		printf("Arr2 = "); PrintArray(&cArray<int>::EraseSingle(arr2, 0), TInt);

		puts("\nDeleting 3 elements in arr2 starting from #2 ...");
		printf("Arr2 = "); PrintArray(&cArray<int>::ErasePart(arr2, 2,3), TInt);

		puts("\nSumming arr1 + arr1 ...");
		cArray<int> arr4 = arr1+arr1;
		printf("Arr4 = "); PrintArray(&arr4, TInt);
	}
	catch (cEBaseException &ex)
	{
		printf("Exception: %s\n", ex.what());
	}

	_getch();
	return 0;
}

