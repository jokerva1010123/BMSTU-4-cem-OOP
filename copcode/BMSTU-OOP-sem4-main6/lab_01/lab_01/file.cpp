#include "file.h"

//#include <cstdio>

FILE *open_file(const char *filename)
{
    return fopen(filename, "r");
}


int close_file(FILE *f)
{
    int rc = OK;

    rc = fclose(f);

    return rc;
}
