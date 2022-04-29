#pragma once

#include <stdio.h>

//��������� �����
struct sEdge
{
	int from, to; //������ ����� � �������, ���������� ������
};

//��������� �����
struct sPoint3d
{
	double x, y, z; //���������� �����
};

//������������� ���������� ��������� ����� � �������: ������ ���, ���� �� ������, ���������,
//�� ������� ������, ����������� ������
enum eCodeFile {cfFine, cfNotFound, cfCorrupted, cfOutOfMemory, cfUnknownAction};


eCodeFile LoadPointsCount(FILE *fl, int &n);
eCodeFile LoadEdgesCount(FILE *fl, int &n);
eCodeFile LoadSinglePoint(FILE *fl, sPoint3d *point);
eCodeFile LoadSingleEdge(FILE *fl, sEdge *edge);
