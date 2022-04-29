#ifndef BASE_LOADERMODEL_H
#define BASE_LOADERMODEL_H

#include "builder_model.h"
#include "base_loader.h"

class LoaderBaseModel: public BaseLoader
{
public:
    virtual std::shared_ptr<Object> load(std::shared_ptr<BuilderModel> b) = 0;
};

#endif // BASE_LOADERMODEL_H
