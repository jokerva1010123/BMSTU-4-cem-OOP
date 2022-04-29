//
//		Базовый класс
//
#pragma once
#include <windows.h>

using namespace System;
using namespace System::Windows::Forms;



//базовый класс объекта, связанного с формой
ref class cBaseObject abstract //ref - чтобы можно было Object^, abstract - чтобы можно было = 0;
{
public:
	cBaseObject()
	{
		display = nullptr;
	}
	//"переотрисовать" объект на форме
	virtual void Refresh() = 0;

	//связать объект с элементом формы
	bool LinkTo(Object^ to)
	{
		display = to;
		Refresh();
		return true;
	}

protected:
	Object^ display; //элемент формы, отвечающий за отображение объекта
};

//делегат событий
delegate void dEHandler(cBaseObject^ source);
//делегат событий с параметрами
/*delegate void dEHandlerParam(cBaseObject^ source, sBaseData &data);

//базовый класс данных о событии
struct sBaseData
{
};


//класс таймера для простоя системы
class cTimer
{
public:
	inline static void msleep(int ms)
	{
		Sleep(ms);
	}
};

*/
