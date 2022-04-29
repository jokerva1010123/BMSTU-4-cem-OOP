//
//		��������������� ��������� ������
//

#include "stdafx.h"

#include "render.h"
#include "canvasworks.h"
#include "conversions.h"

//��������� ������������� �����
void DrawSingleEdge(sConvertedPoints *converted, sEasel *easel, sEdge *edge)
{
	DrawLine(easel->canvas,
		CanvasPoint(easel->cx + converted->Xs[edge->from], easel->cy - converted->Ys[edge->from]),
		CanvasPoint(easel->cx + converted->Xs[edge->to], easel->cy - converted->Ys[edge->to])
		);

}

//��������� ���� ������
void DrawEdges(sConvertedPoints *converted, sEasel *easel, sEdgesList *links)
{
	for (int i=0; i<links->count; i++)
	{
		DrawSingleEdge(converted, easel, &(links->edgesArray[i]));
	}
}

/*void DrawAxis(sEasel *easel)
{
	DrawLine(easel->canvas,
		CanvasPoint(0, 10
}*/

void PrepareCanvas(sEasel *easel)
{
	easel->canvas->Clear(easel->backcolor);
}

//��������� ������ �� ��������� � ���������� �����������
void DrawModel(sModel *mdl, sEasel *easel, sRenderData *params)
{
	if (!mdl || !easel || !params)
		return;

	//��������� ����� ������ � ����� ������, � ������ "���������� ������"
	sConvertedPoints *conv = ConvertPoints(&(mdl->points), params);
	if (!conv) return;

	PrepareCanvas(easel);

	//������������ ���� ������
	DrawEdges(conv, easel, &(mdl->edges));

	//FillCanvas(dd->canvas);

	ClearConvertedPoints(conv);

	return;
}