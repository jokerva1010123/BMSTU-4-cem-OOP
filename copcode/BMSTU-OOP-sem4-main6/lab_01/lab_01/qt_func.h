#ifndef QT_FUNC_H
#define QT_FUNC_H

#include "points.h"
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
#endif // QT_FUNC_H
