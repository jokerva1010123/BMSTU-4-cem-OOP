#pragma once

//#include "model.h"
#include "fileworks.h"

//����� ������
struct sEdgesList
{
	int count;			//���������� �����
	sEdge *edgesArray;	//������ �����
};

//������� ������
struct sPointsList
{
	int count;			//���������� ������
	sPoint3d *pointsArray;	//������ ������
};

//������������� ���������� ��������� ������
enum eAllocError {aeFine, aeOutOfMemory};



//����������� ������ ��-��� ��������� ������ ������
void ClearPointsList(sPointsList *p);

//����������� ������ ��-��� ��������� ����� ������
void ClearEdgesList(sEdgesList *e);



//�������� ��������� ������� ������ �� �����
eCodeFile TryLoadPoints(FILE *fl, sPointsList *pd);

//�������� ��������� ���� ������ �� �����
eCodeFile TryLoadEdges(FILE *fl, sEdgesList *adj);




//�������� �������� ������ ��� ��������� ������ ������
eAllocError AllocPointsList(sPointsList *points);

//�������� �������� ������ ��� ��������� ����� ������
eAllocError AllocEdgesLst(sEdgesList *edges);