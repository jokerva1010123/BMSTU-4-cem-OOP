//
//		������ � ������� - �������� �� �����, ��������
//

#include "stdafx.h"

#include "model.h"
#include "model_loadparts.h"

//����������� ������ ��-��� ����������� ������
void ClearModel(sModel *mdl)
{
	ClearPointsList(&(mdl->points));
	ClearEdgesList(&(mdl->edges));
}


//�������� ������ ��� ������ � �������������� � ��������
sModel* InitializeModel()
{
	sModel *mdl = new sModel;
	if (!mdl) return nullptr;

	mdl->edges.count = 0;
	mdl->edges.edgesArray = nullptr;
	mdl->points.count = 0;
	mdl->points.pointsArray = nullptr;
	return mdl;
}

//��������� ������ �� �����
eCodeFile LoadModel(sModel *&mdl, char *filename)
{
	FILE *fl = fopen(filename, "r");
	if (!fl)
		return cfNotFound;

	//��������� �������� ����� � "��������" ������
	sModel *newmodel = InitializeModel();

	if (!newmodel) return cfOutOfMemory;

	eCodeFile res = TryLoadPoints(fl, &(newmodel->points)); //�������� ��������� �����

	if (res != cfFine)
	{
		fclose(fl);
		return res;
	}

	res = TryLoadEdges(fl, &(newmodel->edges)); //�������� ��������� ����
	fclose(fl);

	if (res != cfFine)
	{
		ClearPointsList(&(newmodel->points));
		return res;
	}

	//������� ������������ ������, ���� ��� ����
	if (mdl)
	{
		ClearModel(mdl);
		delete mdl;
	}

	mdl = newmodel; //���������� ��������

	return cfFine;
}


//������ � ������ ������: ��������, ���������� (�������������)
eCodeFile FileProcess(sModel *&mdl, char *filename, eFileAction action)
{
	switch(action)
	{
	case faLoad: //��������� ������
		{
			return LoadModel(mdl, filename);
		}
	case faSave: //��������� ������
		{
			return cfUnknownAction;
		}
	default:
		{
			return cfUnknownAction;
		}
	}
	return cfFine;
}