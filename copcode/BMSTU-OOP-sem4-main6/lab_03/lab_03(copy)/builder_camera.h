#ifndef BUILDER_CAMERA_H
#define BUILDER_CAMERA_H

#include "base_builder.h"
#include "camera.h"

class BuilderCamera: public BaseBuilder
{
public:
    BuilderCamera() = default;
    ~BuilderCamera() = default;

    bool is_build() const override;

    void build() override;

    void build_pos(Point p);

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Camera> p_camera;
};

#endif // BUILDER_CAMERA_H
