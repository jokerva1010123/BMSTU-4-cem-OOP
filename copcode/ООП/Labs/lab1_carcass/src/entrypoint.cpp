//
//		Точка входа, через которую применяются любые действия из интерфейса
//

#include "stdafx.h"

#include "entrypoint.h"
#include "conversions.h"
#include "render.h"
#include "model.h"
#include "actions.h"


//применяем действие, переданное из интерфейса
eCodeFile Apply(eChangeAction action, uChangeData *data)
{
	static sRenderData changes; //изменения производимые в модели
	static sEasel easel;		//мольберт на котором отрисовывать
	static sModel *model = InitializeModel();		//редактируемая модель

	if (!model) return cfOutOfMemory;

	eCodeFile res = cfFine;

	switch (action)
	{
	case caInit: //инициализация холста
		{
			SetCanvas(&easel, data->canvas);
			break;
		}
	case caLoad: //загрузка модели из файла
		{
			res = FileProcess(model, data->filename, faLoad);
			break;
		}
	case caScale: //изменение масштаба модели
		{
			ChangeScale(&changes, data->scale);
			break;
		}
	case caRotate: //изменение углов поворота модели
		{
			ChangeRotation(&changes, data->move);
			break;
		}
	case caSetRot: //установка углов поворота модели
		{
			SetRotation(&changes, data->move);
			break;
		}
	case caShift: //изменение смещения модели
		{
			ChangeShift(&changes, data->move);
			break;
		}

	default: 
		return cfUnknownAction;
	}

	DrawModel(model, &easel, &changes);
	return res;
}