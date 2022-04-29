//
//		Реализация методов базового класса
//
#include "stdafx.h"

#include "base.h"

//конструктор по умолчанию
_cArrayBase::_cArrayBase() : size(0)
{}

//конструктор создания
_cArrayBase::_cArrayBase(int s) : size(s)
{}

//конструктор копирования
_cArrayBase::_cArrayBase(_cArrayBase &origin) : size(origin.size)
{}


//проверка массива на пустоту
/*bool _cArrayBase::Empty() const
{	return (size>0);	}*/

//получение размера массива
int _cArrayBase::GetSize() const
{	return size;	}