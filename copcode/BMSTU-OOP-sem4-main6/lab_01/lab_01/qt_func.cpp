#include "qt_func.h"

int my_addline(drawer &arg, dot &p1, dot &p2)
{
    p1.x = p1.x + arg.w / 2;
    p1.y = p1.y + arg.h / 2;

    p2.x = p2.x + arg.w / 2;
    p2.y = p2.y + arg.h / 2;

    arg.scene->addLine(p1.x, p1.y, p2.x, p2.y);

    return OK;
}


int my_clear(my_scene &scene)
{
    scene->clear();

    return OK;
}
