#ifndef LOAD_MODEL_CONTROLLER_H
#define LOAD_MODEL_CONTROLLER_H

#include <utility>
#include "builder_model.h"
#include "abstract_load_controller.h"
#include "base_loader.h"
#include "base_loadermodel.h"

class LoadModelController: public AbstractLoadController
{
public:
    explicit LoadModelController(std::shared_ptr<LoaderBaseModel> l)
        : builder(new BuilderModel), loader(std::move(l)) {}


    ~LoadModelController() = default;

    std::shared_ptr<Model> load(std::string &name) override;

private:
    std::shared_ptr<BuilderModel> builder;
    std::shared_ptr<LoaderBaseModel> loader;

};

#endif // LOAD_MODEL_CONTROLLER_H
