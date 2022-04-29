//
//		��������� ����� ��������������� �� ������
//
#include "stdafx.h"

#include "canvasworks.h"

//������ 2�-����� �� ���� ���������
sCanvasPoint CanvasPoint(int fromX, int fromY)
{
	sCanvasPoint pt;
	pt.x = fromX;
	pt.y = fromY;
	return pt;
}

//������ ����� �� ������ ����� ����� �������
void DrawLine(Graphics^ canvas, sCanvasPoint &from, sCanvasPoint &to, Color clr)
{
	Pen^ drawpen = gcnew Pen(clr);
	canvas->DrawLine(drawpen, from.x, from.y,  to.x, to.y);
	delete drawpen;
}
