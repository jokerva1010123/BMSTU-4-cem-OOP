//
//		��������� ���������� ��������� ������
//

#include "stdafx.h"

#include "actions.h"
#include "render.h"	
#include "conversions.h"
#include "matrixworks.h"


// ---------------------------------------------------------------------------

//������������� ������ �� ���������
void SetCanvas(sEasel *easel, sCanvasContainer *canv)
{
	easel->canvas = canv->pb->CreateGraphics();
	easel->cx = canv->pb->Width / 2;
	easel->cy = canv->pb->Height / 2;
	easel->backcolor = canv->pb->BackColor;
}

//��������� �������� ������
void ChangeScale(sRenderData *renderdata, double scale)
{
	renderdata->M = scale;
}

//������� ������
void ChangeRotation(sRenderData *renderdata, sMove move)
{
	renderdata->fx += move.dx;
	renderdata->fy += move.dy;
	renderdata->fz += move.dz;
}

//��������� ����� ������
void SetRotation(sRenderData *renderdata, sMove move)
{
	renderdata->fx = move.dx;
	renderdata->fy = move.dy;
	renderdata->fz = move.dz;
}

//�������� ������
void ChangeShift(sRenderData *renderdata, sMove move)
{
	renderdata->dx += move.dx;
	renderdata->dy += move.dy;
	renderdata->dz += move.dz;
}