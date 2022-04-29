//
//		�������������� ������ � ����� ����� �� ������
//

#include "stdafx.h"

#include "conversions.h"
#include "canvasworks.h"
#include "matrixworks.h"
#include "fileworks.h"

//������ ������� ��������������: ����� � ���� � ���� � ���� � �������
double *GetConversionMatrix(sRenderData *data)
{
	double *ShiftMatrix = Get3DShiftMatrix(data->dx, data->dy, data->dz); //�������� �� �
	if (!ShiftMatrix)
	{
		return nullptr;
	}
	double *RotateZMatrix = Get3DRotateZMatrix(data->fz); //������� ������ OZ
	if (!RotateZMatrix)
	{
		delete ShiftMatrix;
		return nullptr;
	}
	double *RotateYMatrix = Get3DRotateYMatrix(data->fy); //������� ������ OY
	if (!RotateYMatrix)
	{
		delete RotateZMatrix;
		delete ShiftMatrix;
		return nullptr;
	}
	double *RotateXMatrix = Get3DRotateXMatrix(data->fx); //������� ������ OX
	if (!RotateXMatrix)
	{
		delete ShiftMatrix;
		delete RotateYMatrix;
		delete RotateZMatrix;
		return nullptr;
	}
	double *ScaleMatrix = Get3DScaleMatrix(data->M); //�������������� ������������ �
	if (!ScaleMatrix)
	{
		delete ShiftMatrix;
		delete RotateZMatrix;
		delete RotateYMatrix;
		delete RotateXMatrix;
		return nullptr;
	}
	
	//������� �������� - �������� �� ��� ��������

	double *matr1 = MultMatrixXMatrix(ShiftMatrix, RotateZMatrix, 3); //Shift � Z
	if (!matr1)
	{
		delete ShiftMatrix;
		delete RotateZMatrix;
		delete RotateYMatrix;
		delete RotateXMatrix;
		delete ScaleMatrix;
		return nullptr;
	}
	double *matr2 = MultMatrixXMatrix(matr1, RotateYMatrix, 3); // x Y
	if (!matr2)
	{
		delete ShiftMatrix;
		delete RotateZMatrix;
		delete RotateYMatrix;
		delete RotateXMatrix;
		delete ScaleMatrix;
		delete matr1;
		return nullptr;
	}
	double *matr3 = MultMatrixXMatrix(matr2, RotateXMatrix, 3); //x X
	if (!matr3)
	{
		delete ShiftMatrix;
		delete RotateZMatrix;
		delete RotateYMatrix;
		delete RotateXMatrix;
		delete ScaleMatrix;
		delete matr2;
		delete matr1;
		return nullptr;
	}
	double *res = MultMatrixXMatrix(matr3, ScaleMatrix, 3); //x Scale
	if (!res)
	{
		delete ShiftMatrix;
		delete RotateZMatrix;
		delete RotateYMatrix;
		delete RotateXMatrix;
		delete ScaleMatrix;
		delete matr1;
		delete matr2;
		delete matr3;
		return nullptr;
	}

	delete ShiftMatrix;
	delete RotateZMatrix;
	delete RotateYMatrix;
	delete RotateXMatrix;
	delete ScaleMatrix;
	delete matr1;
	delete matr2;
	delete matr3;

	return res;
}

//����������� ������������ ����� � ����� �� ������
sCanvasPoint* ConvertSinglePoint(sPoint3d *p, double *ConvMatrix)
{
	double *pVector = new double[4];	//������������� ����� � ���� �������
	if (!pVector)						//4 ���������� ����� ��� ������������� ������� ��������
		return nullptr;
	
	pVector[0] = p->x;
	pVector[1] = p->y;
	pVector[2] = p->z;
	pVector[3] = 1;

	//�������� ������ ����� �� ������� �������������� - �������� ����� ����� � ��������� �������������
	double *conversion = MultVectorXMatrix(pVector, ConvMatrix, 3);
	delete pVector;

	if (!conversion) return nullptr;

	sCanvasPoint *res = new sCanvasPoint;
	if (!res)
	{
		delete conversion;
		return nullptr;
	}

	res->x = (int) conversion[0];
	res->y = (int) conversion[1];
	delete conversion;

	return res;
}

sConvertedPoints* AllocateConvertedPoints(int count)
{
	sConvertedPoints *conv = new sConvertedPoints;
	if (!conv) return nullptr;

	int *Xs = new int [count]; //������ ��������� �
	if (!Xs)
	{
		delete conv;
		return nullptr;
	}
	int *Ys = new int [count]; //������ ��������� �
	if (!Ys)
	{
		delete conv;
		delete Xs;
		return nullptr;
	}

	conv->count = count;
	conv->Xs = Xs;
	conv->Ys = Ys;
	return conv;
}

//����������� ��������� ����� � ����� �� ������
sConvertedPoints* ConvertPoints(sPointsList *points, sRenderData *params)
{
	sConvertedPoints *conv = AllocateConvertedPoints(points->count); //��������� ����� �� ������

	if (!conv) return nullptr;

	double *ConvMatrix = GetConversionMatrix(params); //������� ��������������
	if (!ConvMatrix)
	{
		delete conv;
		return nullptr;
	}

	//����������� �����; ����� Z ����� ��������������� ����������
	for (int i=0; i<points->count; i++)
	{
		sCanvasPoint *point = ConvertSinglePoint(points->pointsArray + i, ConvMatrix);
		conv->Xs[i] = point->x;
		conv->Ys[i] = point->y;
		delete point;
	}

	delete ConvMatrix;

	return conv;
}

//������� ��������� ��������������� �����
void ClearConvertedPoints(sConvertedPoints *converted)
{
	delete converted->Xs;
	delete converted->Ys;
	delete converted;
}