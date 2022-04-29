#include "actions.h"

//#include <cmath>
//#include "points.h"
//#include "my_error.h"

int scale_point(dot &point, const dot &center, const scale &options)
{
    point.x = point.x * options.kx + (1 - options.kx) * center.x;
    point.y = point.y * options.ky + (1 - options.ky) * center.y;
    point.z = point.z * options.kz + (1 - options.kz) * center.z;

    return OK;
}

int scale_all_point(dots_all &points, const dot &center, const scale &options)
{
    int rc = OK;

    for (int i = 0; i < points.count && rc == OK; ++i)
        rc = scale_point(points.data[i], center, options);

    return rc;
}


double sinus(const double &alpha)
{
    return sin(alpha * M_PI / 360);
}


double cosine(const double &alpha)
{
    return cos(alpha * M_PI / 360);
}


int turn_x(dot &point, const dot &center, const double &alpha)
{
    double my_cos = cosine(alpha);
    double my_sin = sinus(alpha);
    double buf_y = point.y;

    point.y = center.y + (point.y - center.y) * my_cos +
            (point.z - center.z) * my_sin;
    point.z = center.z + (point.z - center.z) * my_cos -
            (buf_y - center.y) * my_sin;

    return OK;
}


int turn_y(dot &point, const dot &center, const double &alpha)
{
    double my_cos = cosine(alpha);
    double my_sin = sinus(alpha);
    double buf_x = point.x;

    point.x = center.x + (point.x - center.x) * my_cos +
            (point.z - center.z) * my_sin;
    point.z = center.z + (point.z - center.z) * my_cos -
            (buf_x - center.x) * my_sin;

    return OK;
}


int turn_z(dot &point, const dot &center, const double &alpha)
{
    double my_cos = cosine(alpha);
    double my_sin = sinus(alpha);
    double buf_x = point.x;

    point.x = center.x + (point.x - center.x) * my_cos +
            (point.y - center.y) * my_sin;
    point.y = center.y + (point.y - center.y) * my_cos -
            (buf_x - center.x) * my_sin;

    return OK;
}


int turn_all_point(dots_all &points, const dot &center, const turn &options)
{
    int rc = OK;

    for (int i = 0; i < points.count && rc == OK; ++i)
        rc = turn_x(points.data[i], center, options.alpha_x);

    for (int i = 0; i < points.count && rc == OK; ++i)
        rc = turn_y(points.data[i], center, options.alpha_y);

    for (int i = 0; i < points.count && rc == OK; ++i)
        rc = turn_z(points.data[i], center, options.alpha_z);

    return rc;
}


int move_point(dot &point, const move &options)
{
    point.x += options.dx;
    point.y += options.dy;
    point.z += options.dz;

    return OK;
}


int move_all_point(dots_all &points, dot &center, const move &options)
{    
    int rc = OK;

    for (int i = 0; i < points.count && rc == OK; ++i)
        rc = move_point(points.data[i], options);

    if (rc == OK)
        rc = move_point(center, options);

    return rc;
}
