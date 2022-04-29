#ifndef DRAWING_H
#define DRAWING_H

#include "line.h"
#include "qt_func.h"
#include "points.h"
#include "my_error.h"

#include <QGraphicsView>

//typedef struct drawer drawer;
//typedef struct points points;

int draw_line(one_link &dots, drawer &arg);
int draw_lines(drawer &arg, const dot *dots, const lines_all &lines);


#endif // DRAWING_H
