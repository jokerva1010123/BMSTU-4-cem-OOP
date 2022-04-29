#pragma once


#include <stdio.h>

#include "model_loadparts.h"


//структура модели
struct sModel
{
	sPointsList points; //вершины модели
	sEdgesList edges; //ребра модели
};

//перечислитель действий над файлом модели: загрузка, сохранение
enum eFileAction {faLoad, faSave};

//выделяет память под модель и инициализирует её пустотой
sModel* InitializeModel();

//работа с файлом модели: загрузка, сохранение
eCodeFile FileProcess(sModel *&mdl, char *filename, eFileAction action);