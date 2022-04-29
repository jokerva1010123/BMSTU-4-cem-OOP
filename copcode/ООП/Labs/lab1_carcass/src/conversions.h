#pragma once

#include "model_loadparts.h"

//�������� ������
struct sMove
{
	double dx;
	double dy;
	double dz;
};

//��������� �������������
struct sRenderData
{
	double fx, fy, fz; //���� ��������
	double dx, dy, dz; //�������� ������
	double M; //������� ���������
};

//����� � ������������� �����������
//������������ ��� ��������������� ���������
struct sConvertedPoints
{
	int count;	//����� �����
	int *Xs;	//X i-� �����
	int *Ys;	//Y i-� �����
};

sConvertedPoints* ConvertPoints(sPointsList *points, sRenderData *params);

void ClearConvertedPoints(sConvertedPoints *converted);