//
//		������ � ������� �� ������ ������ - ��������������� �������� ���������
//

#include "stdafx.h"

#include <stdio.h>
#include "fileworks.h"


//���������� �� ����� ����� �����
eCodeFile LoadPointsCount(FILE *fl, int &n)
{
	int count;

	if (fscanf(fl, "%d", &count) != 1)
		return cfCorrupted;
	
	n = count;
	return cfFine;
}

//���������� �� ����� ����� ����
eCodeFile LoadEdgesCount(FILE *fl, int &n)
{
	int count;

	if (fscanf(fl, "%d", &count) != 1)
		return cfCorrupted;
	
	n = count;
	return cfFine;
}

//���������� �� ����� ����� �����
eCodeFile LoadSinglePoint(FILE *fl, sPoint3d *point)
{
	if (fscanf(fl, "%lf %lf %lf", &point->x, &point->y, &point->z) != 3)
		return cfCorrupted;
	
	return cfFine;
}

//���������� �� ����� ������ �����
eCodeFile LoadSingleEdge(FILE *fl, sEdge *edge)
{
	if (fscanf(fl, "%d %d", &edge->from, &edge->to) != 2)
		return cfCorrupted;
	
	return cfFine;
}
