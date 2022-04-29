#include "line.h"

static int read_count(lines_all &lines, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;

    if (fscanf(f, "%d", &lines.count) != 1)
        return FILE_FORMAT_ERROR;

    if (lines.count <= 0)
        return FILE_FORMAT_ERROR;

    return SUCCESS;
}

int lines_init(lines_all &lines)
{
    lines.count = 0;
    lines.data = NULL;

    return SUCCESS;
}

int lines_free(lines_all &lines)
{
    lines.count = 0;
    if (lines.data)
        free(lines.data);
    return SUCCESS;
}

int lines_allocate(lines_all &lines)
{
    int rc = SUCCESS;

    lines.data = (line*)malloc(sizeof(line) * lines.count);
    if (lines.data == NULL)
        rc = MEMORY_ERROR;

    return rc;
}

int lines_copy(lines_all &buf_lines, const lines_all &lines)
{
    buf_lines.count = lines.count;
    buf_lines.data = lines.data;

    return SUCCESS;
}

int read_line(line &link, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;

    int rc = fscanf(f, "%d%d", &link.point1, &link.point2);
    if (rc != 2)
        rc = FILE_FORMAT_ERROR;
    else
        rc = SUCCESS;

    return rc;
}

int read_all_lines(lines_all &lines, FILE *f)
{
    if (lines.data == NULL)
        return MEMORY_ERROR;

    if (f == NULL)
        return FILE_OPEN_ERROR;
    int rc = SUCCESS;

    for (int i = 0; rc == SUCCESS && i < lines.count; ++i)
        if (read_line(lines.data[i], f))
            rc = FILE_FORMAT_ERROR;
    return rc;
}

int lines_actions(lines_all &lines, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;

    int rc = read_count(lines, f);
    if (rc != SUCCESS)
        return rc;

    rc = lines_allocate(lines);
    if (rc == SUCCESS)
    {
        rc = read_all_lines(lines, f);
        if (rc == FILE_FORMAT_ERROR)
            lines_free(lines);
    }

    return rc;
}

one_link get_point(const dot *dots, const line &link)
{
    static one_link ps;

    if (dots != NULL)
    {
        ps.p1 = dots[link.point1];
        ps.p2 = dots[link.point2];
    }

    return ps;
}
