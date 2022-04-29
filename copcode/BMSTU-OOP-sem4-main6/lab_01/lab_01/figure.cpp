#include "figure.h"
#include <iostream>

figure &figure_init()
{
    static figure figur;

    points_init(figur.points);
    lines_init(figur.lines);
    point_init(figur.center);

    return figur;
}

void figure_free(figure &figur)
{
    points_free(figur.points);

    lines_free(figur.lines);
}

int figure_copy(figure &buf_figur, const figure &figur)
{
    int rc = OK;

    rc = points_copy(buf_figur.points, figur.points);
    if (rc == OK)
    {
        rc = lines_copy(buf_figur.lines, figur.lines);
        if (rc == OK)
            rc = point_copy(buf_figur.center, figur.center);
    }

    return rc;
}


int figure_load(figure &figur, const char *filename)
{
    int rc = OK;

    if (filename == NULL)
        return FILE_OPEN_ERROR;

    FILE *f = open_file(filename);
    if (f == NULL)
        return FILE_OPEN_ERROR;

    figure buf_figur = figure_init();

    rc = points_actions(buf_figur.points, f);
    if (rc == OK)
    {
        rc = lines_actions(buf_figur.lines, f);
        if (rc != OK)
            points_free(buf_figur.points);
    }

    if (rc == OK)
    {
        figure_free(figur);
        figure_copy(figur, buf_figur);
    }

    rc = close_file(f);

    return rc;
}

int figure_draw(drawer &arg, const dots_all &dots, const lines_all &lines)
{
    if (dots.count == 0)
        return NO_POINTS;

    int rc = OK;
    rc = my_clear(arg.scene);
    if (rc == OK)
        rc = draw_lines(arg, dots.data, lines);

    return rc;
}


int figure_move(dots_all &dots, dot &center, const move &options)
{
    return move_all_point(dots, center, options);
}

int figure_scale(dots_all &dots, const dot &center, const scale &options)
{
    return scale_all_point(dots, center, options);
}

int figure_turn(dots_all &dots, const dot &center, const turn &options)
{
    return turn_all_point(dots, center, options);
}
