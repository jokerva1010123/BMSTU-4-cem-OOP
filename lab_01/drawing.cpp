#include "drawing.h"

int change(drawer &arg, dot &p1, dot &p2)
{
    p1.x = p1.x + arg.w / 2;
    p1.y = p1.y + arg.h / 2;

    p2.x = p2.x + arg.w / 2;
    p2.y = p2.y + arg.h / 2;

    return SUCCESS;
}

int my_addline(drawer &arg, dot &p1, dot &p2)
{

    arg.scene->addLine(p1.x, p1.y, p2.x, p2.y);

    return SUCCESS;
}

int my_clear(my_scene &scene)
{
    scene->clear();
    return SUCCESS;
}

int draw_lines(drawer &arg, const dots_all &dots, const lines_all &lines)
{
    one_link ps;
    int rc = SUCCESS;
    for (int i = 0; rc == SUCCESS && i < lines.count; ++i)
    {
        ps = get_point(dots.data, lines.data[i]);
        change(arg, ps.p1, ps.p2);
        rc = my_addline(arg, ps.p1, ps.p2);
    }
    return rc;
}

