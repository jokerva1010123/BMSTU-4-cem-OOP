//
//		Реализация методов шаблонного класса
//
#pragma once

#include "array.h"
#include "my_exceptions.h"
#include <stdarg.h>

//конструктор по умолчанию
template<typename T>
cArray<T>::cArray() : size(0), data(nullptr)
{}

//конструктор создания
template<typename T>
cArray<T>::cArray(int n)
{
	if (n<0)
	{
		cESizeException ex;
		throw ex;
	}

	size = n;
	data = new T [n];

	if (!data)
	{
		cEMemoryException ex;
		throw ex;
	}
}

//конструктор создания с инициализацией
template<typename T>
cArray<T>::cArray(int n, T first, ...)
{
	if (n<0)
	{
		cESizeException ex;
		throw ex;
	}

	size = n;
	data = new T [n];

	if (!data)
	{
		cEMemoryException ex;
		throw ex;
	}

	/*
	T *ptr = &first;

	for (int i=0; i<n; i++, ptr++)
		data[i] = *ptr;
	*/
	va_list vl;
	va_start(vl, n);

	for (int i=0; i<n; i++)
	{
		data[i] = va_arg(vl, T);
	}

	va_end(vl);
}

//конструктор копирования
template<typename T>
cArray<T>::cArray(const cArray<T> &origin)
{
	size = origin.size;
	data = new T [size];

	if (!data)
	{
		cEMemoryException ex;
		throw ex;
	}

	for (int i=0; i<size; i++)
	{
		data[i] = origin.data[i];
	}
}


//деструктор
template<typename T>
cArray<T>::~cArray()
{
	if (data)
		delete [] data;
}




//выделение части массива
template<typename T>
cArray<T> cArray<T>::Splice(int start, int len)
{
	if (start<0 || start>=size || len<0 || (start+len)>size)
	{
		cEIndexException ex;
		throw ex;
	}

	cArray<T> arr(len);

	for (int i=0; i<len; i++)
	{
		arr[i] = data[start+i]
	}

	return arr;
}

/*
//вставка элемента
template<typename T>
void cArray<T>::InsertSingle(const T el, int index)
{
	size += 1;
	T *Ndata = new T [size];
	//копируем элементы в новый массив
	for (int i=0; i<index; i++)
	{
		Ndata[i] = data[i];
	}
	Ndata[index] = el;
	for (int i=index+1; i<size; i++)
	{
		Ndata[i] = data[i-1];
	}

	delete [] data;
	data = Ndata;
}

//удаление элемента
template<typename T>
void cArray<T>::EraseSingle(int index)
{
	size -= 1;
	T *Ndata = new T [size];
	//копируем элементы в новый массив
	for (int i=0; i<index; i++)
	{
		Ndata[i] = data[i];
	}
	for (int i=index; i<size; i++)
	{
		Ndata[i] = data[i+1];
	}

	delete [] data;
	data = Ndata;
}

//вставка элементов другого массива
template<typename T>
void cArray<T>::InsertArray(const cArray<T> &arr, int index)
{
	int len = arr.GetSize();
	//не мучаемся с вставкой пустоты
	if (len == 0) return;

	size += len;
	T *Ndata = new T [size];

	//копируем старые элементы (слева)
	for (int i=0; i<index; i++)
		Ndata[i] = data[i];

	//вставляем элементы массива
	for (int i=index; i<index+len; i++)
		Ndata[i] = arr[i-index];

	//копируем старые элементы (справа)
	for (int i=index+len; i<size; i++)
		Ndata[i] = data[i-len];

	delete [] data;
	data = Ndata;
}

//удаление части массива
template<typename T>
void cArray<T>::ErasePart(int start, int len)
{
	size -= len;
	T *Ndata = new T [size];
	//копируем элементы в новый массив
	for (int i=0; i<start; i++)
	{
		Ndata[i] = data[i];
	}
	for (int i=start; i<size; i++)
	{
		Ndata[i] = data[i+len];
	}

	delete [] data;
	data = Ndata;
}
*/

//вставка элемента
template<typename T>
cArray<T> cArray<T>::InsertSingle(const cArray<T> &origin, const T el, int index)
{
	if (index<0 || index>=origin.size)
	{
		cEIndexException ex;
		throw ex;
	}

	int size = origin.GetSize() + 1;
	cArray<T> res(size);
	//копируем элементы в новый массив
	for (int i=0; i<index; i++)
	{
		res[i] = origin[i];
	}
	res[index] = el;
	for (int i=index+1; i<size; i++)
	{
		res[i] = origin[i-1];
	}

	return res;
}

//удаление элемента
template<typename T>
cArray<T> cArray<T>::EraseSingle(const cArray<T> &origin, int index)
{
	if (index<0 || index>=origin.size)
	{
		cEIndexException ex;
		throw ex;
	}

	int size = origin.GetSize() - 1;
	cArray<T> res(size);
	//копируем элементы в новый массив
	for (int i=0; i<index; i++)
	{
		res[i] = origin[i];
	}
	for (int i=index; i<size; i++)
	{
		res[i] = origin[i+1];
	}

	return res;
}

//вставка элементов другого массива
template<typename T>
cArray<T> cArray<T>::InsertArray(const cArray<T> &origin, const cArray<T> &arr, int index)
{
	if (index<0 || index>=origin.size)
	{
		cEIndexException ex;
		throw ex;
	}

	int len = arr.GetSize();
	//не мучаемся с вставкой пустоты
	if (len == 0) return cArray<T>(origin);

	int size = origin.size + len;
	cArray<T> res(size);

	//копируем старые элементы (слева)
	for (int i=0; i<index; i++)
		res[i] = origin[i];

	//вставляем элементы массива
	for (int i=index; i<index+len; i++)
		res[i] = arr[i-index];

	//копируем старые элементы (справа)
	for (int i=index+len; i<size; i++)
		res[i] = origin[i-len];

	return res;
}

//удаление части массива
template<typename T>
cArray<T> cArray<T>::ErasePart(const cArray<T> &origin, int start, int len)
{
	if (start<0 || start>=origin.size || len<0 || (start+len)>origin.size)
	{
		cEIndexException ex;
		throw ex;
	}

	int size = origin.GetSize() - len;
	cArray<T> res(size);

	//копируем элементы в новый массив
	for (int i=0; i<start; i++)
	{
		res[i] = origin[i];
	}
	for (int i=start; i<size; i++)
	{
		res[i] = origin[i+len];
	}
	return res;
}



template<typename T>
T&			cArray<T>::operator [] (int i)
{
	if (i<0 || i>=size)
	{
		cEIndexException ex;
		throw ex;
	}
	return data[i];
}

template<typename T>
const T&	cArray<T>::operator [] (int i) const
{
	if (i<0 || i>=size)
	{
		cEIndexException ex;
		throw ex;
	}
	return data[i];
}

template<typename T>
cArray<T>	cArray<T>::operator = (const cArray<T>& right)
{
	if (this==&right)
		return right;

	size = right.size;

	if (data)
		delete [] data;

	data = new T [size];
	if (!data)
	{
		cEMemoryException ex;
		throw ex;
	}

	for (int i=0; i<size; i++)
	{
		data[i] = right.data[i];
	}

	return this;
}

template<typename T>
bool		cArray<T>::operator == (const cArray<T>& with) const
{
	int is = with.size;
	if (size != with.size)
		return false;

	for (int i=0; i<size; i++)
	{
		if (data[i] != with[i])
			return false;
	}

	return true;
}

template<typename T>
cArray<T>	operator + (const cArray<T>& left, const cArray<T>& right)
{
	int ls = left.GetSize();
	int rs = right.GetSize();
	cArray<T> res(ls+rs);

	for (int i=0; i<ls; i++)
	{
		res[i] = left[i];
	}
	for (int i=0; i<right.GetSize(); i++)
	{
		res[ls+i] = right[i];
	}

	return res;
}