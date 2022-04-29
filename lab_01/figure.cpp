#include "figure.h"

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
    int rc = SUCCESS;

    rc = points_copy(buf_figur.points, figur.points);
    if (rc == SUCCESS)
    {
        rc = lines_copy(buf_figur.lines, figur.lines);
        if (rc == SUCCESS)
            rc = point_copy(buf_figur.center, figur.center);
    }

    return rc;
}

int figur_input(figure &figur, FILE *f)
{
    int rc = points_actions(figur.points, f);
    if (rc == SUCCESS)
    {
        rc = lines_actions(figur.lines, f);
        if (rc != SUCCESS)
            points_free(figur.points);
    }
    return rc;
}

int figure_load(figure &figur, const char *filename)
{
    int rc = SUCCESS;

    if (filename == NULL)
        return FILE_OPEN_ERROR;

    FILE *f = fopen(filename, "r");
    if (f == NULL)
        return FILE_OPEN_ERROR;

    figure buf_figur = figure_init();

    rc = figur_input(buf_figur, f);
    fclose(f);

    if (rc == SUCCESS)
    {
        figure_free(figur);
        figure_copy(figur, buf_figur);
    }
    return rc;
}

int figure_draw(figure &figur, drawer &arg)
{
    if (figur.points.count == 0)
        return NO_POINTS;

    int rc = SUCCESS;
    rc = my_clear(arg.scene);
    if (rc == SUCCESS)
        rc = draw_lines(arg, figur.points, figur.lines);

    return rc;
}

int figure_move(figure &figur, const move &options)
{
    return move_all_point(figur.points, figur.center, options);
}

int figure_scale(figure &figur, const scale &options)
{
    return scale_all_point(figur.points, figur.center, options);
}

int figure_turn(figure &figur, const turn &options)
{
    return turn_all_point(figur.points, figur.center, options);
}
