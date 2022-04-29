#ifndef OPERATIONS_H
#define OPERATIONS_H

#define _USE_MATH_DEFINES

#include <cmath>
#include "dots.h"
#include "my_error.h"

struct scale
{
    double kx;
    double ky;
    double kz;
};

struct turn
{
    double alpha_x;
    double alpha_y;
    double alpha_z;
};

struct move
{
    double dx;
    double dy;
    double dz;
};

int scale_all_point(dots_all &points, const dot &center, const scale &options);
int turn_point(dot &point, const dot &center, const double &alphax, const double &alphay, const double &alphaz);
int turn_all_point(dots_all &points, const dot &center, const turn &options);
int move_all_point(dots_all &points, dot &center, const move &options);

#endif
