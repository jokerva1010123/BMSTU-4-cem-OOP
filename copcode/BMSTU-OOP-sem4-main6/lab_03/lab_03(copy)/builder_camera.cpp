#include "builder_camera.h"

void BuilderCamera::build()
{
    p_camera = std::make_shared<Camera>();
}

void BuilderCamera::build_pos(Point p)
{
    p_camera->cur_p = p;
}

std::shared_ptr<Object> BuilderCamera::get()
{
    return p_camera;
}

bool BuilderCamera::is_build() const
{
    return (p_camera != nullptr);
}
