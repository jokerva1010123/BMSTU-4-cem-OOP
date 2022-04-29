#ifndef MY_ERROR_H
#define MY_ERROR_H

#include <QMessageBox>

enum error_code
{
    OK,
    FILE_OPEN_ERROR,
    FILE_FORMAT_ERROR,
    MEMORY_ERROR,
    NO_POINTS,
    NO_LINES,
    UNKNOWN_COMMAND,
    SCENE_ERROR
};

int messege_of_error(const error_code &error);

#endif // MY_ERROR_H
