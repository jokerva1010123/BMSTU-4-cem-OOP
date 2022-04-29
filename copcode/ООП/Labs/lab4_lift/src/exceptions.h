#pragma once

#include <exception>

//������� ����� ����������
class cEBaseException : public std::exception
{
public:
	virtual const char* what()
	{
		return "my base exception";
	}
};

//���������� ������������ ���������
class cEUnknownState : public cEBaseException
{
public:
	const char* what()
	{
		return "Object is in illegal state.";
	}
};

//���������� �������
class cEOutOfRange : public cEBaseException
{
public:
	const char* what()
	{
		return "Index of array is out of range.";
	}
};

//���������� ������������ �������
class cENotLinked : public cEBaseException
{
public:
	const char* what()
	{
		return "Object is not linked to any display.";
	}
};