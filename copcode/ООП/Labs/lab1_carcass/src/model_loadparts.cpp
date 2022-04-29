//
//		Работа с компонентами модели
//

#include "stdafx.h"

#include "model_loadparts.h"
#include "fileworks.h"

//освобождает память из-под структуры вершин модели
void ClearPointsList(sPointsList *p)
{
	if (!p)
		return;
	delete p->pointsArray;
	p->pointsArray = nullptr;
	p->count = 0;
}

//освобождает память из-под структуры ребер модели
void ClearEdgesList(sEdgesList *e)
{
	if (!e)
		return;
	delete e->edgesArray;
	e->edgesArray = nullptr;
	e->count = 0;
}

//загружает массив точек в структуру
eCodeFile LoadPoints(FILE *fl, sPointsList *points)
{
	eCodeFile res = cfFine;

	for (int i = 0;  (i < points->count) && (res == cfFine);  i++)
	{
		res = LoadSinglePoint(fl, &(points->pointsArray[i]));
	}
	return res;
}

//загружает массив ребер в структуру
eCodeFile LoadEdges(FILE *fl, sEdgesList *edges)
{
	eCodeFile res = cfFine;

	for (int i = 0;  (i < edges->count) && (res == cfFine);  i++)
	{
		res = LoadSingleEdge(fl, &(edges->edgesArray[i]));
	}
	return res;
}


//пытается выделить память под структуру вершин модели
eAllocError AllocPointsList(sPointsList *points)
{
	points->pointsArray = new sPoint3d[points->count];

	if (!points->pointsArray)
		return aeOutOfMemory;

	return aeFine;
}

//пытается выделить память под структуру ребер модели
eAllocError AllocEdgesList(sEdgesList *edges)
{
	edges->edgesArray = new sEdge[edges->count];

	if (!edges->edgesArray)
		return aeOutOfMemory;

	return aeFine;
}



//пытается загрузить вершины модели из файла
eCodeFile TryLoadPoints(FILE *fl, sPointsList *points)
{	
	eCodeFile res = LoadPointsCount(fl, points->count); //пытаемся получить число точек из файла
	if (res != cfFine) 
		return res;
	
	if (AllocPointsList(points) == aeOutOfMemory) //пытаемся выделить память под точки
		return cfOutOfMemory;

	res = LoadPoints(fl, points); //наконец пытаемся загрузить точки

	if (res != cfFine) //если не удалось - очистим память из-под них
		ClearPointsList(points);

	return res;
}

//пытается загрузить рёбра модели из файла
eCodeFile TryLoadEdges(FILE *fl, sEdgesList *edges)
{
	eCodeFile res = LoadEdgesCount(fl, edges->count); //пытаемся получить число ребер из файла
	if (res != cfFine) 
		return res;

	if (AllocEdgesList(edges) == aeOutOfMemory) //пытаемся выделить память под ребра
		return cfOutOfMemory;

	res = LoadEdges(fl, edges); //наконец пытаемся загрузить ребра

	if (res != cfFine) //если не удалось - очистим память из-под них
		ClearEdgesList(edges);

	return res;
}

