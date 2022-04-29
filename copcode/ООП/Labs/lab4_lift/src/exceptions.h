#pragma once

#include <exception>

//базовый класс исключения
class cEBaseException : public std::exception
{
public:
	virtual const char* what()
	{
		return "my base exception";
	}
};

//исключение неизвестного состояния
class cEUnknownState : public cEBaseException
{
public:
	const char* what()
	{
		return "Object is in illegal state.";
	}
};

//исключение индекса
class cEOutOfRange : public cEBaseException
{
public:
	const char* what()
	{
		return "Index of array is out of range.";
	}
};

//исключение несвязанного объекта
class cENotLinked : public cEBaseException
{
public:
	const char* what()
	{
		return "Object is not linked to any display.";
	}
};