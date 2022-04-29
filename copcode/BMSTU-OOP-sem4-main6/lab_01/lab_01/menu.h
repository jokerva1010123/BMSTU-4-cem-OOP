#ifndef MENU_H
#define MENU_H

#include "actions.h"
#include "drawing.h"
#include "figure.h"
#include "my_error.h"

enum task
{
    START,
    DOWNLOAD_FILE,
    DRAW,
    MOVE,
    SCALE,
    TURN,
    EXIT
};

struct request
{
    task task_f;
    union
    {
        const char *filename;
        drawer draw_f;
        move move_f;
        scale scale_f;
        turn turn_f;
    };
};

//typedef struct request request;

int inquiry(request &data);

#endif // MENU_H
