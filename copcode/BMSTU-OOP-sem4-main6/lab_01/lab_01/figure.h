#ifndef FIGURE_H
#define FIGURE_H

#include "file.h"
#include "points.h"
#include "line.h"
#include "actions.h"
#include "drawing.h"
#include "my_error.h"
#include "qt_func.h"

struct figure
{
    dots_all points;
    lines_all lines;
    dot center;
};

//typedef struct figure figure;

figure &figure_init(void);
void figure_free(figure &figur);
int figure_copy(figure &buf_figur, const figure &figur);
int figure_load(figure &figur, const char *filename);

int figure_draw(drawer &arg, const dots_all &dots, const lines_all &lines);

int figure_move(dots_all &dots, dot &center, const move &options);
int figure_scale(dots_all &dots, const dot &center, const scale &options);
int figure_turn(dots_all &dots, const dot &center, const turn &options);

#endif // FIGURE_H
