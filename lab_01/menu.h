#ifndef MENU_H
#define MENU_H

#include "my_error.h"
#include "operations.h"
#include "drawing.h"
#include "figure.h"

#define    START          1
#define    DOWNLOAD_FILE  2
#define    DRAW           3
#define    MOVE           4
#define    SCALE          5
#define    TURN           6
#define    END            7

struct command
{
    int task_f;
    union
    {
        const char *filename;
        drawer draw_f;
        move move_f;
        scale scale_f;
        turn turn_f;
    };
};

int inquiry(command &data);

#endif // MENU_H
