#ifndef DOTS_H
#define DOTS_H

#include <cstdio>
#include <cstdlib>
#include "my_error.h"

struct dot
{
    double x;
    double y;
    double z;
};

struct dots_all
{
    int count;
    struct dot* data;
};
int read_count(dots_all &points, FILE *f);
int point_init(dot &point);
int points_init(dots_all &points);
int points_free(dots_all &points);
int points_allocate(dots_all &points);

int points_copy(dots_all &buf_points, const dots_all &points);
int point_copy(dot &buf_point, const dot &point);

int read_all_points(dots_all &points, FILE *f);
int points_actions(dots_all &points, FILE *f);


#endif // POINTS_H
