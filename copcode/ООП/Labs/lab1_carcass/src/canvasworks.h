#pragma once

using namespace System;
using namespace System::Drawing;

//����� �� ������
struct sCanvasPoint
{
	int x;
	int y;
};


//������ 2�-����� �� ���� ���������
sCanvasPoint CanvasPoint(int fromX, int fromY);

//������ ����� �� ������ ����� ����� �������
void DrawLine(Graphics^ canvas, sCanvasPoint &from, sCanvasPoint &to, Color clr = Color::Black);