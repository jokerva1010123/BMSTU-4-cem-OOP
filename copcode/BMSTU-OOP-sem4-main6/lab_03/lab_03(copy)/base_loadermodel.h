#ifndef BASE_LOADERMODEL_H
#define BASE_LOADERMODEL_H

#include "builder_model.h"
#include "base_loader.h"

class LoaderBaseModel: public BaseLoader
{
public:
    virtual std::vector<Point<double>> load_points() = 0;
    virtual std::vector<Link> load_links() = 0;
};

#endif // BASE_LOADERMODEL_H
