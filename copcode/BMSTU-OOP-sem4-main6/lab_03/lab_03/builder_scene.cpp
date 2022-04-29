#include "builder_scene.h"

void BuilderScene::build()
{
    p_scene = std::make_shared<Scene>();
}

std::shared_ptr<Object> BuilderScene::get()
{
    return p_scene;
}

void BuilderScene::build_camera(const std::shared_ptr<Camera> &c)
{
    if (is_build())
    {
        p_scene->add_camera(c);
    }
}

void BuilderScene::build_model(const std::shared_ptr<Object> &m)
{
    if (is_build())
    {
        p_scene->add_model(m);
    }
}

bool BuilderScene::is_build() const
{
    return (p_scene != nullptr);
}

