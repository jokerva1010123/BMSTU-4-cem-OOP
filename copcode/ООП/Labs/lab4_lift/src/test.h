#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


public delegate void EHandler(Object^ source);


public ref class Manager //��������
{	
public:
	event EHandler^ Start; //������ ��������, ����������� �� �������
	event EHandler^ Stop;

	void InvokeOnStart()
	{
		Start(this);
		DEBUGPRINT("�������� ������� � ��������..");
	}
	void InvokeOnStop()
	{
		Stop(this);
		DEBUGPRINT("�������� ������ � ��������..");
	}
};


public ref class Watcher //���������
{
public:
	Watcher(Manager^ m)
	{
		//m->Stop += gcnew EHandler(this, &Watcher::OnStop); //& - ��������� ����� ������
	}
	void OnStart(Object^ source) //��������� ����� f �� ������������� �������. ����� ����� ����������� method, ����� ����������� ������ �������, ����������� �� ������������� �������
	{
		DEBUGPRINT("������� ������� �������");
	}
	void OnStop(Object^ source) //��������� ����� f �� ������������� �������. ����� ����� ����������� method, ����� ����������� ������ �������, ����������� �� ������������� �������
	{
		DEBUGPRINT("������� ������ �������");
	}
};


