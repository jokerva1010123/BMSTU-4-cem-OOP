#pragma once

using namespace System;
using namespace System::Drawing;

//точка на экране
struct sCanvasPoint
{
	int x;
	int y;
};


//создаёт 2д-точку из двух координат
sCanvasPoint CanvasPoint(int fromX, int fromY);

//рисует линию на холсте между двумя точками
void DrawLine(Graphics^ canvas, sCanvasPoint &from, sCanvasPoint &to, Color clr = Color::Black);