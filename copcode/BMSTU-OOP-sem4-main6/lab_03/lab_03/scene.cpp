#include "scene.h"
#include <iterator>

std::vector<std::shared_ptr<Object>> Scene::get_model()
{
    return model_->get_object_s();
}

std::shared_ptr<Composite> Scene::get_composite()
{
    return model_;
}

std::vector<std::shared_ptr<Camera>> Scene::get_camera()
{
    return camera_;
}


void Scene::add_model(const std::shared_ptr<Object> &m)
{
    model_->add(m);
}

void Scene::remove_model(const size_t i)
{
    auto t = model_->begin();
    std::advance(t, i);
    model_->remove(t);
}


void Scene::add_camera(const std::shared_ptr<Camera> &c)
{
    camera_.push_back(c);
}

void Scene::remove_camera(const size_t i)
{
    auto t = camera_.begin();
    std::advance(t, i);
    camera_.erase(t);
}
