#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


public delegate void EHandler(Object^ source);


public ref class Manager //издатель
{	
public:
	event EHandler^ Start; //списки объектов, подписанных на события
	event EHandler^ Stop;

	void InvokeOnStart()
	{
		Start(this);
		DEBUGPRINT("инвокаем онстарт в менагере..");
	}
	void InvokeOnStop()
	{
		Stop(this);
		DEBUGPRINT("инвокаем онстоп в менагере..");
	}
};


public ref class Watcher //подписчик
{
public:
	Watcher(Manager^ m)
	{
		//m->Stop += gcnew EHandler(this, &Watcher::OnStop); //& - потомучто метод класса
	}
	void OnStart(Object^ source) //подписали метод f на возникновение события. Когда начнёт выполняться method, будут выполняться методы классов, подписанных на возникновение события
	{
		DEBUGPRINT("вызыван онстарт ватчера");
	}
	void OnStop(Object^ source) //подписали метод f на возникновение события. Когда начнёт выполняться method, будут выполняться методы классов, подписанных на возникновение события
	{
		DEBUGPRINT("вызыван онстоп ватчера");
	}
};


