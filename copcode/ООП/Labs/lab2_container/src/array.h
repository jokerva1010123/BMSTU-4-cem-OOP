//
//		Шаблонный класс массива
//
#pragma once

#include "base.h"

//шаблонный класс - массив элементов произвольного типа
template<typename T>
class cArray : public _cArrayBase
{
protected:
	T *data; //непосредственно сам массив элементов

public:
	//конструктор по умолчанию
	cArray();
	//конструктор создания
	cArray(int n);
	//конструктор создания с инициализацией
	cArray(int n, T first, ...);
	//конструктор копирования
	cArray(const cArray &origin);

	//деструктор
	~cArray();


	//выделение части массива
	cArray<T> Splice(int start, int len);
	/*
	//вставка элемента
	void InsertSingle(const T el, int index);

	//удаление элемента
	void EraseSingle(int index);

	//вставка элементов другого массива
	void InsertArray(const cArray<T> &arr, int index);

	//удаление части массива
	void ErasePart(int start, int len);
	*/

	//вставка элемента
	static cArray<T> InsertSingle(const cArray<T> &origin, const T el, int index);

	//удаление элемента
	static cArray<T> EraseSingle(const cArray<T> &origin, int index);

	//вставка элементов другого массива
	static cArray<T> InsertArray(const cArray<T> &origin, const cArray<T> &arr, int index);

	//удаление части массива
	static cArray<T> ErasePart(const cArray<T> &origin, int start, int len);


	//перегруженные операторы
	T&			operator [] (int i);
	const T&	operator [] (int i) const;
	cArray<T>	operator = (const cArray<T>& right);
	bool		operator == (const cArray<T>& with) const;
	friend cArray<T>	operator + (const cArray<T>& left, const cArray<T>& right)
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
	} //конкатенация;
};

#include "array.hpp" //реализация методов