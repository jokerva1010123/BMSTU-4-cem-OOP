#include "operations.h"

int scale_all_point(dots_all &points, const dot &center, const scale &options)
{
    int rc = SUCCESS;
    for (int i = 0; rc == SUCCESS && i< points.count; ++i)
    {
        points.data[i].x = points.data[i].x * options.kx + (1 - options.kx) * center.x;
        points.data[i].y = points.data[i].y * options.ky + (1 - options.ky) * center.y;
        points.data[i].z = points.data[i].z * options.kz + (1 - options.kz) * center.z;
    }
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

int move_to_center(dot &point, const dot &center)
{
    point.x -= center.x;
    point.y -= center.y;
    point.z -= center.z;
    return SUCCESS;
}

int turns(dot &point, const double &alphax, const double &alphay, const double &alphaz)
{
    int buf_x = point.x;
    int buf_y = point.y;
    point.x = point.x * cosine(alphay) + point.z * sinus(alphay);
    point.x = point.x * cosine(alphaz) + point.y * sinus(alphaz);

    point.y = point.y * cosine(alphax) + point.z * sinus(alphax);
    point.y = point.y * cosine(alphaz) - buf_x * sinus(alphaz);

    point.z = point.z * cosine(alphax) - buf_y * sinus(alphax);
    point.z = point.z * cosine(alphay) - buf_x * sinus(alphay);
    return SUCCESS;
}

int move_back(dot &point, const dot &center)
{
   point.x += center.x;
   point.y += center.y;
   point.z += center.z;
   return SUCCESS;
}

int turn_point(dot &point, const dot &center, const double &alphax, const double &alphay, const double &alphaz)
{
    move_to_center(point, center);
    turns(point, alphax, alphay, alphaz);
    move_back(point, center);
    return SUCCESS;
}

int turn_all_point(dots_all &points, const dot &center, const turn &options)
{
    int rc = SUCCESS;

    for (int i = 0; rc == SUCCESS && i < points.count; ++i)
        rc = turn_point(points.data[i], center, options.alpha_x, options.alpha_y, options.alpha_z);

    return rc;
}

int move_all_point(dots_all &points, dot &center, const move &options)
{
    int rc = SUCCESS;

    for (int i = 0; rc == SUCCESS && i < points.count; ++i)
    {
        points.data[i].x += options.dx;
        points.data[i].y += options.dy;
        points.data[i].z += options.dz;
    }
    center.x += options.dx;
    center.y += options.dy;
    center.z += options.dz;

    return rc;
}
