#include "manager_scene_creator.h"


void SceneManagerCreator::create_instance() {
    static std::shared_ptr<SceneManager> manager(new SceneManager());

    manager_ = manager;
}


std::shared_ptr<SceneManager> SceneManagerCreator::create_man()
{
    if (manager_ == nullptr)
    {
        create_instance();
    }

    return manager_;
}


