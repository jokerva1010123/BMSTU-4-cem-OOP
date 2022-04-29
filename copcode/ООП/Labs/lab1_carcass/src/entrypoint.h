#pragma once

#include <gcroot.h>

#include "render.h"
#include "conversions.h"
#include "fileworks.h"

//������������� ������: ���������������� ������, ��������� �� �����, ��������������, �������,
//���������� ���� ��������, ����������
enum eChangeAction {caInit, caLoad, caScale, caRotate, caSetRot, caShift};

//������������ ������ � �������� ������
union uChangeData
{
	sMove move;		//��������
	double scale;	//�������
	char mb;		//������� ������ ����
	sCanvasContainer *canvas;	//������ ��� ������
	char *filename;	//��� ����� ��� ��������
};


//��������������� ���������� ���� � ��������� ���������
eCodeFile Apply(eChangeAction action, uChangeData *data);