#ifndef MANAGER_SCENE_H
#define MANAGER_SCENE_H


#include "scene.h"
#include "base_manager.h"

class SceneManager: public BaseManager
{
public:
    SceneManager();
//    SceneManager(const SceneManager&) = delete;
//    SceneManager& operator=(const SceneManager&) = delete;

    ~SceneManager() = default;

    std::shared_ptr<Scene> get_scene() const;
    std::shared_ptr<Camera> get_camera() const;

    void set_scene(std::shared_ptr<Scene> s);
    void set_camera(const size_t &camera_n);

private:
    std::shared_ptr<Scene> scene_;
    std::shared_ptr<Camera> cur_camera_;

};

#endif // MANAGER_SCENE_H
