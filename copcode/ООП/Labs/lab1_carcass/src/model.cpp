//
//		Работа с моделью - загрузка из файла, удаление
//

#include "stdafx.h"

#include "model.h"
#include "model_loadparts.h"

//освобождает память из-под содержимого модели
void ClearModel(sModel *mdl)
{
	ClearPointsList(&(mdl->points));
	ClearEdgesList(&(mdl->edges));
}


//выделяет память под модель и инициализирует её пустотой
sModel* InitializeModel()
{
	sModel *mdl = new sModel;
	if (!mdl) return nullptr;

	mdl->edges.count = 0;
	mdl->edges.edgesArray = nullptr;
	mdl->points.count = 0;
	mdl->points.pointsArray = nullptr;
	return mdl;
}

//загрузить модель из файла
eCodeFile LoadModel(sModel *&mdl, char *filename)
{
	FILE *fl = fopen(filename, "r");
	if (!fl)
		return cfNotFound;

	//загружать элементы будем в "буферную" модель
	sModel *newmodel = InitializeModel();

	if (!newmodel) return cfOutOfMemory;

	eCodeFile res = TryLoadPoints(fl, &(newmodel->points)); //пытаемся загрузить точки

	if (res != cfFine)
	{
		fclose(fl);
		return res;
	}

	res = TryLoadEdges(fl, &(newmodel->edges)); //пытаемся загрузить рёбра
	fclose(fl);

	if (res != cfFine)
	{
		ClearPointsList(&(newmodel->points));
		return res;
	}

	//удаляем существующую модель, если она была
	if (mdl)
	{
		ClearModel(mdl);
		delete mdl;
	}

	mdl = newmodel; //возвращаем буферную

	return cfFine;
}


//работа с файлом модели: загрузка, сохранение (нереализовано)
eCodeFile FileProcess(sModel *&mdl, char *filename, eFileAction action)
{
	switch(action)
	{
	case faLoad: //загрузить модель
		{
			return LoadModel(mdl, filename);
		}
	case faSave: //сохранить модель
		{
			return cfUnknownAction;
		}
	default:
		{
			return cfUnknownAction;
		}
	}
	return cfFine;
}