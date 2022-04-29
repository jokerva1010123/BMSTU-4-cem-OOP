//
//		Базовый класс массива
//
#pragma once


//абстрактный класс массива
class _cArrayBase
{
public:
	//конструктор по умолчанию
	_cArrayBase();

	//конструктор создания
	_cArrayBase(int s);

	//конструктор копирования
	_cArrayBase(_cArrayBase &origin);

	//получение размера массива
	int GetSize() const;

	//проверка массива на пустоту
	//bool Empty() const;

protected:
	int size; //размер массива

};