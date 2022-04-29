#include <memory>
#include "director_camera.h".h"

void CameraDirector::set_builer(std::shared_ptr<BuilderCamera> b)
{
    builder_ = std::move(b);
}

std::shared_ptr<Camera> CameraDirector::build(const Point p)
{
    builder_->build_pos(p);

    return builder_->get();
}
