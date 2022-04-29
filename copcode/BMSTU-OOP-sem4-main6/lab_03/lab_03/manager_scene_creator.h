#ifndef MANAGER_SCENE_CREATOR_H
#define MANAGER_SCENE_CREATOR_H

#include <memory>
#include "manager_scene.h"

class SceneManagerCreator
{
public:
    std::shared_ptr<SceneManager> create_man();


private:
    std::shared_ptr<SceneManager> manager_;

    void create_instance();
};

#endif // MANAGER_SCENE_CREATOR_H
