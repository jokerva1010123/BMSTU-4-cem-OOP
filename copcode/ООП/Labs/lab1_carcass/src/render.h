#pragma once

#include <gcroot.h>
#include "model.h"
#include "conversions.h"
#include "matrixworks.h"

using namespace System::Drawing;

//������ ��� ������
struct sCanvasContainer
{
	gcroot<System::Windows::Forms::PictureBox^> pb;
};

//�������� ��� ���������
struct sEasel
{
	gcroot<Graphics^> canvas;	//��� �����
	gcroot<Color> backcolor;	//���� ����
	//Graphics^ canvas;
	//Color backcolor;
	int cx, cy;					//����� ������
};

//��������� ������ �� ��������� � ���������� �����������
void DrawModel(sModel *mdl, sEasel *easel, sRenderData *params);