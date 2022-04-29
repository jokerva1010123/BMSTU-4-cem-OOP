#include "drawing.h"

//#include "line.h"
//#include "points.h"
//#include <QGraphicsView>

int draw_line(one_link &dots, drawer &arg)
{
    int rc = OK;

    rc = my_addline(arg, dots.p1, dots.p2);

    return rc;
}


int draw_lines(drawer &arg, const dot *dots, const lines_all &lines)
{
    one_link ps;

    int rc = OK;

    for (int i = 0; i < lines.count && rc == OK; ++i)
    {
        ps = get_point(dots, lines.data[i]);
        rc = draw_line(ps, arg);
    }

    return rc;
}

