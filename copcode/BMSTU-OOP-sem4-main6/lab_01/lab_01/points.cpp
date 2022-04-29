#include "points.h"

//#include <cstdio>
//#include <cstdlib>
//#include "my_error.h"

static int read_count(int &n, FILE *f)
{
    if (f == NULL)
    {
        return FILE_OPEN_ERROR;
    }

    int rc = OK;

    if (fscanf(f, "%d", &n) != 1)
    {
        rc = FILE_FORMAT_ERROR;
    }

    if (n <= 0)
    {
        rc = FILE_OPEN_ERROR;
    }

    return rc;
}

int point_init(dot &point)
{
    point.x = 0;
    point.y = 0;
    point.z = 0;

    return OK;
}

int points_init(dots_all &points)
{
    points.count = 0;
    points.data = NULL;

    return OK;
}

int points_free(dots_all &points)
{
    points.count = 0;

    if (points.data)
    {
        free(points.data);
    }

    return OK;
}

int points_allocate(dots_all &points, const int &count)
{
    int rc = OK;
    points.count = count;

    points.data = (dot*)malloc(sizeof(dot) * count);
    if (points.data == NULL)
    {
        rc = MEMORY_ERROR;
    }

    return rc;
}

int point_copy(dot &buf_point, const dot &point)
{
    buf_point.x = point.x;
    buf_point.y = point.y;
    buf_point.z = point.z;

    return OK;
}

int points_copy(dots_all &buf_points, const dots_all &points)
{
    buf_points.count = points.count;
    buf_points.data = points.data;

    return OK;
}


int read_point(dot &point, FILE *f)
{
    if (f == NULL)
    {
        return FILE_OPEN_ERROR;
    }

    int rc = OK;

    rc = fscanf(f, "%lf%lf%lf", &point.x, &point.y, &point.z);
    if (rc != 3)
    {
        rc = FILE_FORMAT_ERROR;
    }
    else
    {
        rc = OK;
    }

    return rc;
}


int read_all_points(dot *points, const int &count, FILE *f)
{
    if (points == NULL)
    {
        return MEMORY_ERROR;
    }

    if (f == NULL)
    {
        return FILE_OPEN_ERROR;
    }


    int rc = OK;

    for (int i = 0; i < count && rc == OK; ++i)
    {
        if (read_point(points[i], f))
        {
            rc = FILE_FORMAT_ERROR;
        }
    }
    return rc;
}


int points_actions(dots_all &points, FILE *f)
{
    if (f == NULL)
    {
        return FILE_OPEN_ERROR;
    }

    int count = 0, rc = OK;

    rc = read_count(count, f);
    if (rc != OK)
    {
        return rc;
    }

    if (count <= 0)
    {
        return NO_POINTS;
    }

    rc = points_allocate(points, count);
    if (rc == OK)
    {
        rc = read_all_points(points.data, count, f);
        if (rc == FILE_FORMAT_ERROR)
        {
            points_free(points);
        }
    }

    return rc;
}
