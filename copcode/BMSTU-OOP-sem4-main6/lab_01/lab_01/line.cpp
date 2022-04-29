#include "line.h"

//#include "iostream"
//#include "points.h"
//#include "my_error.h"

static int read_count(int &n, FILE *f)
{

    if (f == NULL)
    {
        return FILE_OPEN_ERROR;
    }

    int rc = OK;

    if (fscanf(f, "%d", &n) != 1)
    {
        rc = FILE_FORMAT_ERROR;
    }

    if (n <= 0)
    {
        rc = FILE_FORMAT_ERROR;
    }

    return rc;
}

int lines_init(lines_all &lines)
{
    lines.count = 0;
    lines.data = NULL;

    return OK;
}

int lines_free(lines_all &lines)
{
    lines.count = 0;
    if (lines.data)
    {
        free(lines.data);
    }
    return OK;
}


int lines_allocate(lines_all &lines, const int &count)
{
    int rc = OK;

    lines.count = count;

    lines.data = (line*)malloc(count * sizeof(line));
    if (lines.data == NULL)
    {
        rc = MEMORY_ERROR;
    }

    return rc;
}

int lines_copy(lines_all &buf_lines, const lines_all &lines)
{
    buf_lines.count = lines.count;
    buf_lines.data = lines.data;

    return OK;
}

int read_line(line &link, FILE *f)
{
    if (f == NULL)
    {
        return FILE_OPEN_ERROR;
    }

    int rc = OK;

    rc = fscanf(f, "%d%d", &link.point1, &link.point2);
    if (rc != 2)
    {
        rc = FILE_FORMAT_ERROR;
    }
    else
    {
        rc = OK;
    }

    return rc;
}


int read_all_lines(line *lines, const int &count, FILE *f)
{
    if (lines == NULL)
    {
        return MEMORY_ERROR;
    }

    if (f == NULL)
    {
        return FILE_OPEN_ERROR;
    }

    int rc = OK;

    if (lines == NULL || f == NULL)
    {
        return MEMORY_ERROR;
    }

    for (int i = 0; i < count && rc == OK; ++i)
    {
        if (read_line(lines[i], f))
        {
            rc = FILE_FORMAT_ERROR;
        }
    }

    return rc;
}


int lines_actions(lines_all &lines, FILE *f)
{
    if (f == NULL)
    {
        return FILE_OPEN_ERROR;
    }

    int count = 0, rc = OK;
    rc = read_count(count, f);
    if (rc != OK)
    {
        return rc;
    }

    if (count <= 0)
    {
        return NO_POINTS;
    }

    rc = lines_allocate(lines, count);
    if (rc == OK)
    {
        rc = read_all_lines(lines.data, count, f);
        if (rc == FILE_FORMAT_ERROR)
        {
            lines_free(lines);
        }
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
