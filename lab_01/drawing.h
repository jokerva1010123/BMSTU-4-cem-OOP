#ifndef DRAWING_H
#define DRAWING_H

#include "line.h"
#include "dots.h"
#include "my_error.h"

#include <QGraphicsView>

typedef QGraphicsScene* my_scene;

struct drawer
{
    my_scene scene;
    int w;
    int h;
};

int my_addline(drawer &arg, dot &p1, dot &p2);
int my_clear(my_scene &scene);
int draw_lines(drawer &arg, const dots_all &dots, const lines_all &lines);

#endif // DRAWING_H
