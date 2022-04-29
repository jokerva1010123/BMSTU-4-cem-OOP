#include "file.h"

FILE *open_file(const char *filename)
{
    return fopen(filename, "r");
}

int close_file(FILE *f)
{
    int rc = SUCCESS;

    rc = fclose(f);

    return rc;
}
