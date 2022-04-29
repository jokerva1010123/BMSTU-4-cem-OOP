//
//		������� �����
//
#pragma once
#include <windows.h>

using namespace System;
using namespace System::Windows::Forms;



//������� ����� �������, ���������� � ������
ref class cBaseObject abstract //ref - ����� ����� ���� Object^, abstract - ����� ����� ���� = 0;
{
public:
	cBaseObject()
	{
		display = nullptr;
	}
	//"��������������" ������ �� �����
	virtual void Refresh() = 0;

	//������� ������ � ��������� �����
	bool LinkTo(Object^ to)
	{
		display = to;
		Refresh();
		return true;
	}

protected:
	Object^ display; //������� �����, ���������� �� ����������� �������
};

//������� �������
delegate void dEHandler(cBaseObject^ source);
//������� ������� � �����������
/*delegate void dEHandlerParam(cBaseObject^ source, sBaseData &data);

//������� ����� ������ � �������
struct sBaseData
{
};


//����� ������� ��� ������� �������
class cTimer
{
public:
	inline static void msleep(int ms)
	{
		Sleep(ms);
	}
};

*/
