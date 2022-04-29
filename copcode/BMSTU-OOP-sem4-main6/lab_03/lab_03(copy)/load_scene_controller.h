#ifndef LOAD_SCENE_CONTROLLER_H
#define LOAD_SCENE_CONTROLLER_H

#include <utility>
#include "builder_scene.h"
#include "abstract_load_controller.h"
#include "base_loader.h"
#include "base_loaderscene.h"

class LoadSceneController: public AbstractLoadController
{
public:
    explicit LoadSceneController(std::shared_ptr<LoaderBaseScene> l)
        : builder(new BuilderScene()), loader(std::move(l)) {}

    ~LoadSceneController() = default;

    std::shared_ptr<Object> load(std::string &name) override;

private:
    std::shared_ptr<BuilderScene> builder;
    std::shared_ptr<LoaderBaseScene> loader;

};

#endif // LOAD_SCENE_CONTROLLER_H
