#ifndef LINE_H
#define LINE_H

#include "points.h"
#include "my_error.h"

struct one_link
{
    dot p1;
    dot p2;
};

struct line
{
    int point1;
    int point2;
};

struct lines_all
{
    int count;
    line *data;
};

//typedef struct line line;
//typedef struct lines_all lines_all;

int lines_init(lines_all &lines);
int lines_free(lines_all &lines);
int lines_allocate(lines_all &lines, const int &count);

int lines_copy(lines_all &buf_lines, const lines_all &lines);
int read_line(line &link, FILE *f);
int read_all_lines(line *lines, const int &count, FILE *f);
int lines_actions(lines_all &lines, FILE *f);

one_link get_point(const dot *dots, const line &link);

#endif // LINE_H
