#include "scene.h"
#include <iterator>

void Scene::add(const std::shared_ptr<Object> &m)
{
    object_->add(m);
}

void Scene::remove(const size_t number)
{
    auto t = object_->begin();
    std::advance(t, number);
    object_->remove(t);
}
