#pragma once

#include <stdio.h>

//структура ребра
struct sEdge
{
	int from, to; //номера точек в массиве, соединённых ребром
};

//структура точки
struct sPoint3d
{
	double x, y, z; //координаты тчоек
};

//перечислитель результата обработки файла с моделью: ошибок нет, файл не найден, поврежден,
//не хватает памяти, неизвестная ошибка
enum eCodeFile {cfFine, cfNotFound, cfCorrupted, cfOutOfMemory, cfUnknownAction};


eCodeFile LoadPointsCount(FILE *fl, int &n);
eCodeFile LoadEdgesCount(FILE *fl, int &n);
eCodeFile LoadSinglePoint(FILE *fl, sPoint3d *point);
eCodeFile LoadSingleEdge(FILE *fl, sEdge *edge);
