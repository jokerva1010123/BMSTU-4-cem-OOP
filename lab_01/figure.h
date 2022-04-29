#ifndef FIGURE_H
#define FIGURE_H

#include "dots.h"
#include "line.h"
#include "operations.h"
#include "drawing.h"
#include "my_error.h"

struct figure
{
    dots_all points;
    lines_all lines;
    dot center;
};

figure &figure_init(void);
int figur_input(figure &figur, FILE *f);
void figure_free(figure &figur);
int figure_copy(figure &buf_figur, const figure &figur);
int figure_load(figure &figur, const char *filename);
int figure_draw(figure &figur, drawer &arg);
int figure_move(figure &figur, const move &options);
int figure_scale(figure &figur, const scale &options);
int figure_turn(figure &figur, const turn &options);

#endif // FIGURE_H
