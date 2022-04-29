#pragma once

//#include "model.h"
#include "fileworks.h"

//ребра модели
struct sEdgesList
{
	int count;			//количество ребер
	sEdge *edgesArray;	//массив ребер
};

//вершины модели
struct sPointsList
{
	int count;			//количество вершин
	sPoint3d *pointsArray;	//массив вершин
};

//перечислитель результата выделения памяти
enum eAllocError {aeFine, aeOutOfMemory};



//освобождает память из-под структуры вершин модели
void ClearPointsList(sPointsList *p);

//освобождает память из-под структуры ребер модели
void ClearEdgesList(sEdgesList *e);



//пытается загрузить вершины модели из файла
eCodeFile TryLoadPoints(FILE *fl, sPointsList *pd);

//пытается загрузить рёбра модели из файла
eCodeFile TryLoadEdges(FILE *fl, sEdgesList *adj);




//пытается выделить память под структуру вершин модели
eAllocError AllocPointsList(sPointsList *points);

//пытается выделить память под структуру ребер модели
eAllocError AllocEdgesLst(sEdgesList *edges);