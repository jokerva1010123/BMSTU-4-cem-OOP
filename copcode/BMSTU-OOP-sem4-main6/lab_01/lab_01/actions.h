#ifndef ACTIONS_H
#define ACTIONS_H

#define _USE_MATH_DEFINES

#include <cmath>
#include "points.h"
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

//typedef struct move move;
//typedef struct scale scale_r;
//typedef struct turn turn;

int scale_point(dot &point, const dot &center, const scale &options);
int scale_all_point(dots_all &points, const dot &center, const scale &options);

int turn_x(dot &point, const dot &center, const double &alpha);
int turn_y(dot &point, const dot &center, const double &alpha);
int turn_z(dot &point, const dot &center, const double &alpha);
int turn_all_point(dots_all &points, const dot &center, const turn &options);

int move_point(dot &point, dot &center, const move &options);
int move_all_point(dots_all &points, dot &center, const move &options);

#endif // ACTIONS_H
