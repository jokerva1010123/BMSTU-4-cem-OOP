#ifndef _IOMODULE_H_
#define _IOMODULE_H_

#include "constants.h"
#include "figure.h"
#include "io_links.h"
#include "io_points.h"

#include <cstdio>
#include <cstdlib>

err_t read_from_file(figure_t &figure, const char *const filename);
void destroy_figure(figure_t &figure); 
void destroy_projection(fpr_t &projection);

#endif
