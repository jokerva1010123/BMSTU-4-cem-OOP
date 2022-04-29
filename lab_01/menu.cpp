#include "menu.h"

int inquiry(command &data)
{
    int rc = SUCCESS;
    static figure figur = figure_init();

    switch (data.task_f)
    {
        case START:
            break;
        case DOWNLOAD_FILE:
            rc = figure_load(figur, data.filename);
            break;
        case DRAW:
            rc = figure_draw(figur, data.draw_f);
            break;
        case MOVE:
            rc = figure_move(figur, data.move_f);
            break;
        case SCALE:
            rc = figure_scale(figur, data.scale_f);
            break;
        case TURN:
            rc = figure_turn(figur, data.turn_f);
            break;
        case END:
            figure_free(figur);
            break;
        default:
            rc = UNKNOWN_COMMAND;
    }

    return rc;
}
