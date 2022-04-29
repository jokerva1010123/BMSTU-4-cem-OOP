#ifndef FILE_H
#define FILE_H

#include <cstdio>
#include "my_error.h"

FILE *open_file(const char *filename);
int close_file(FILE *f);

#endif // FILE_H
