#include "dots.h"

int read_count(dots_all &points, FILE *f)
{
    int rc = SUCCESS;
    if (fscanf(f, "%d", &points.count) != 1)
        rc = FILE_FORMAT_ERROR;

    if (points.count <= 0)
        rc = FILE_OPEN_ERROR;

    return rc;
}

int point_init(dot &point)
{
    point.x = 0;
    point.y = 0;
    point.z = 0;

    return SUCCESS;
}

int points_init(dots_all &points)
{
    points.count = 0;
    points.data = NULL;

    return SUCCESS;
}

int points_free(dots_all &points)
{
    points.count = 0;
    if (points.data)
        free(points.data);
    return SUCCESS;
}

int points_allocate(dots_all &points)
{
    int rc = SUCCESS;

    points.data = (dot*)malloc(sizeof(dot) * points.count);
    if (points.data == NULL)
        rc = MEMORY_ERROR;
    return rc;
}

int point_copy(dot &buf_point, const dot &point)
{
    buf_point.x = point.x;
    buf_point.y = point.y;
    buf_point.z = point.z;

    return SUCCESS;
}

int points_copy(dots_all &buf_points, const dots_all &points)
{
    buf_points.count = points.count;
    buf_points.data = points.data;

    return SUCCESS;
}

int read_point(dot &point, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;

    int rc = fscanf(f, "%lf%lf%lf", &point.x, &point.y, &point.z);
    if (rc != 3)
        rc = FILE_FORMAT_ERROR;
    else
        rc = SUCCESS;
    return rc;
}


int read_all_points(dots_all &points, FILE *f)
{
    if (points.data == NULL)
        return MEMORY_ERROR;

    if (f == NULL)
        return FILE_OPEN_ERROR;
    int rc = SUCCESS;

    for (int i = 0; rc == SUCCESS && i < points.count; ++i)
        if (read_point(points.data[i], f))
            rc = FILE_FORMAT_ERROR;
    return rc;
}

int points_actions(dots_all &points, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;

    int rc = read_count(points, f);

    if (rc != SUCCESS)
        return rc;

    rc = points_allocate(points);
    if (rc == SUCCESS)
    {
        rc = read_all_points(points, f);
        if (rc == FILE_FORMAT_ERROR)
            points_free(points);
    }

    return rc;
}
