//
//		����� �����, ����� ������� ����������� ����� �������� �� ����������
//

#include "stdafx.h"

#include "entrypoint.h"
#include "conversions.h"
#include "render.h"
#include "model.h"
#include "actions.h"


//��������� ��������, ���������� �� ����������
eCodeFile Apply(eChangeAction action, uChangeData *data)
{
	static sRenderData changes; //��������� ������������ � ������
	static sEasel easel;		//�������� �� ������� ������������
	static sModel *model = InitializeModel();		//������������� ������

	if (!model) return cfOutOfMemory;

	eCodeFile res = cfFine;

	switch (action)
	{
	case caInit: //������������� ������
		{
			SetCanvas(&easel, data->canvas);
			break;
		}
	case caLoad: //�������� ������ �� �����
		{
			res = FileProcess(model, data->filename, faLoad);
			break;
		}
	case caScale: //��������� �������� ������
		{
			ChangeScale(&changes, data->scale);
			break;
		}
	case caRotate: //��������� ����� �������� ������
		{
			ChangeRotation(&changes, data->move);
			break;
		}
	case caSetRot: //��������� ����� �������� ������
		{
			SetRotation(&changes, data->move);
			break;
		}
	case caShift: //��������� �������� ������
		{
			ChangeShift(&changes, data->move);
			break;
		}

	default: 
		return cfUnknownAction;
	}

	DrawModel(model, &easel, &changes);
	return res;
}