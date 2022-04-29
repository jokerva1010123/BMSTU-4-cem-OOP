#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "composite.h"

class Scene: public Object
{
public:
    Scene() : model_(new Composite) {}

    ~Scene() override = default;

    void add_model(const std::shared_ptr<Object> &m);
    void remove_model(const size_t model_n);

    void add_camera(const std::shared_ptr<Camera> &c);
    void remove_camera(const size_t cam_n);

    std::vector<std::shared_ptr<Object>> get_model();
    std::shared_ptr<Composite> get_composite();
    std::vector<std::shared_ptr<Camera>> get_camera();


protected:
    std::shared_ptr<Composite> model_;
    std::vector<std::shared_ptr<Camera>> camera_;

private:
    void accept(std::shared_ptr<Visitor> v) override {}
    void reform(const Point &m,
                const Point &s,
                const Point &t) override {}
};

#endif // SCENE_H
