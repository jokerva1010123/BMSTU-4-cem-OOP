#include "builder_camera.h"

void BuilderCamera::build()
{
    p_camera = std::make_shared<Camera>();
}

void BuilderCamera::build_pos(double x, double y, double z)
{

}

std::shared_ptr<Object> BuilderCamera::get()
{
    return p_camera;
}

bool BuilderCamera::is_build() const
{
    return (p_camera != nullptr);
}
