#ifndef MY_ERROR_H
#define MY_ERROR_H

#include <QMessageBox>

#define    SUCCESS             0
#define    FILE_OPEN_ERROR     1
#define    FILE_FORMAT_ERROR   2
#define    MEMORY_ERROR        3
#define    NO_POINTS           4
#define    NO_LINES            5
#define    UNKNOWN_COMMAND     6
#define    SCENE_ERROR         7

int show_error(const int &error);

#endif // MY_ERROR_H
