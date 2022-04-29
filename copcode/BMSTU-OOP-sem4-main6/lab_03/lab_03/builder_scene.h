#ifndef BUILDER_SCENE_H
#define BUILDER_SCENE_H

#include "base_builder.h"
#include "scene.h"

class BuilderScene: public BaseBuilder
{
public:
    BuilderScene() = default;
    ~BuilderScene() = default;

    bool is_build() const override;

    void build() override;

    void build_model(const std::shared_ptr<Object> &m);
    void build_camera(const std::shared_ptr<Camera> &c);

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Scene> p_scene;
};

#endif // BUILDER_SCENE_H
