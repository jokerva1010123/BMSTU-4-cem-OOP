#pragma once

#include <gcroot.h>
#include "model.h"
#include "conversions.h"
#include "matrixworks.h"

using namespace System::Drawing;

//обёртка для холста
struct sCanvasContainer
{
	gcroot<System::Windows::Forms::PictureBox^> pb;
};

//мольберт для рисования
struct sEasel
{
	gcroot<Graphics^> canvas;	//сам холст
	gcroot<Color> backcolor;	//цвет фона
	//Graphics^ canvas;
	//Color backcolor;
	int cx, cy;					//центр холста
};

//отрисовка модели на мольберте с указанными параметрами
void DrawModel(sModel *mdl, sEasel *easel, sRenderData *params);