#include "manager_load.h"
#include <utility>
#include "load_model_controller.h"
#include "loader_filemodel.h"

LoadManager::LoadManager()
{
    std::shared_ptr<LoaderBaseModel> l(new LoaderFileModel);

    loader_ = std::shared_ptr<AbstractLoadController>(new LoadModelController(l));
}

std::shared_ptr<Object> LoadManager::load(std::string &name)
{
    return loader_->load(name);
}

void LoadManager::set_loader(std::shared_ptr<AbstractLoadController> l)
{
    loader_ = std::move(l);
}
