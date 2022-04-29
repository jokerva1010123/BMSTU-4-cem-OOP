#pragma once


#include <stdio.h>

#include "model_loadparts.h"


//��������� ������
struct sModel
{
	sPointsList points; //������� ������
	sEdgesList edges; //����� ������
};

//������������� �������� ��� ������ ������: ��������, ����������
enum eFileAction {faLoad, faSave};

//�������� ������ ��� ������ � �������������� � ��������
sModel* InitializeModel();

//������ � ������ ������: ��������, ����������
eCodeFile FileProcess(sModel *&mdl, char *filename, eFileAction action);