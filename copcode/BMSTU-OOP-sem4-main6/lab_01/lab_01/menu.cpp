#include "menu.h"

//#include "actions.h"
//#include "drawing.h"
//#include "figure.h"
//#include "my_error.h"

int inquiry(request &data)
{
    int rc = OK;
    static figure figur = figure_init();

    switch (data.task_f)
    {
        case START:
            break;
        case DOWNLOAD_FILE:
            rc = figure_load(figur, data.filename);
            break;
        case DRAW:
            rc = figure_draw(data.draw_f, figur.points, figur.lines);
            break;
        case MOVE:
            rc = figure_move(figur.points, figur.center, data.move_f);
            break;
        case SCALE:
            rc = figure_scale(figur.points, figur.center, data.scale_f);
            break;
        case TURN:
            rc = figure_turn(figur.points, figur.center, data.turn_f);
            break;
        case EXIT:
            figure_free(figur);
            break;
        default:
            rc = UNKNOWN_COMMAND;
    }

    return rc;
}
