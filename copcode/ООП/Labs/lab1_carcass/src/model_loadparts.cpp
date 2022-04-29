//
//		������ � ������������ ������
//

#include "stdafx.h"

#include "model_loadparts.h"
#include "fileworks.h"

//����������� ������ ��-��� ��������� ������ ������
void ClearPointsList(sPointsList *p)
{
	if (!p)
		return;
	delete p->pointsArray;
	p->pointsArray = nullptr;
	p->count = 0;
}

//����������� ������ ��-��� ��������� ����� ������
void ClearEdgesList(sEdgesList *e)
{
	if (!e)
		return;
	delete e->edgesArray;
	e->edgesArray = nullptr;
	e->count = 0;
}

//��������� ������ ����� � ���������
eCodeFile LoadPoints(FILE *fl, sPointsList *points)
{
	eCodeFile res = cfFine;

	for (int i = 0;  (i < points->count) && (res == cfFine);  i++)
	{
		res = LoadSinglePoint(fl, &(points->pointsArray[i]));
	}
	return res;
}

//��������� ������ ����� � ���������
eCodeFile LoadEdges(FILE *fl, sEdgesList *edges)
{
	eCodeFile res = cfFine;

	for (int i = 0;  (i < edges->count) && (res == cfFine);  i++)
	{
		res = LoadSingleEdge(fl, &(edges->edgesArray[i]));
	}
	return res;
}


//�������� �������� ������ ��� ��������� ������ ������
eAllocError AllocPointsList(sPointsList *points)
{
	points->pointsArray = new sPoint3d[points->count];

	if (!points->pointsArray)
		return aeOutOfMemory;

	return aeFine;
}

//�������� �������� ������ ��� ��������� ����� ������
eAllocError AllocEdgesList(sEdgesList *edges)
{
	edges->edgesArray = new sEdge[edges->count];

	if (!edges->edgesArray)
		return aeOutOfMemory;

	return aeFine;
}



//�������� ��������� ������� ������ �� �����
eCodeFile TryLoadPoints(FILE *fl, sPointsList *points)
{	
	eCodeFile res = LoadPointsCount(fl, points->count); //�������� �������� ����� ����� �� �����
	if (res != cfFine) 
		return res;
	
	if (AllocPointsList(points) == aeOutOfMemory) //�������� �������� ������ ��� �����
		return cfOutOfMemory;

	res = LoadPoints(fl, points); //������� �������� ��������� �����

	if (res != cfFine) //���� �� ������� - ������� ������ ��-��� ���
		ClearPointsList(points);

	return res;
}

//�������� ��������� ���� ������ �� �����
eCodeFile TryLoadEdges(FILE *fl, sEdgesList *edges)
{
	eCodeFile res = LoadEdgesCount(fl, edges->count); //�������� �������� ����� ����� �� �����
	if (res != cfFine) 
		return res;

	if (AllocEdgesList(edges) == aeOutOfMemory) //�������� �������� ������ ��� �����
		return cfOutOfMemory;

	res = LoadEdges(fl, edges); //������� �������� ��������� �����

	if (res != cfFine) //���� �� ������� - ������� ������ ��-��� ���
		ClearEdgesList(edges);

	return res;
}

