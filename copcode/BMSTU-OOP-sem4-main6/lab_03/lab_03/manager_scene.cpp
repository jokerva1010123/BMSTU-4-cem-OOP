#include <utility>
#include <memory>
#include "manager_scene.h"

SceneManager::SceneManager()
{
    scene_ = std::make_shared<Scene>();
}


std::shared_ptr<Scene> SceneManager::get_scene() const
{
    return scene_;
}

std::shared_ptr<Camera> SceneManager::get_camera() const
{
    return cur_camera_;
}

void SceneManager::set_scene(std::shared_ptr<Scene> s)
{
    scene_ = std::move(s);
}

void SceneManager::set_camera(const size_t &n)
{
    auto c = scene_->get_camera().at(n);
    cur_camera_ = c;
}
