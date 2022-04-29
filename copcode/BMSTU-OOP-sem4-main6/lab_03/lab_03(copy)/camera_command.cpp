#include "camera_command.h"

#include "camera.h"
#include "manager_reform_creator.h"
#include "manager_scene_creator.h"


AddCamera::AddCamera(const double x,
                     const double y,
                     const double z)
    : x_pos(x), y_pos(y), z_pos(z) {}

void AddCamera::execute()
{
    Point cp(x_pos, y_pos, z_pos);

    std::shared_ptr<Camera> cam(new Camera);
    cam->reform(cp, cp, cp);

    auto sm = SceneManagerCreator().create_man();

    sm->get_scene()->add_camera(cam);
    sm->set_camera(sm->get_scene()->get_camera().size() - 1);
}

RemoveCamera::RemoveCamera(const size_t &cn)
    : camera_n(cn) {}

void RemoveCamera::execute()
{
     SceneManagerCreator().create_man()->get_scene()->remove_camera(camera_n);
}

MoveCamera::MoveCamera(const size_t &cam_n,
                       const double &x,
                       const double &y)
    : camera_n(cam_n), shift_x(x), shift_y(y) {}

void MoveCamera::execute()
{
    Point s(shift_x, shift_y, 0);
    auto camera = SceneManagerCreator().create_man()->get_scene()->get_camera().at(camera_n);
    ReformManagerCreator().create_man()->reform_obj(camera, s, s, s);
}

SetCamera::SetCamera(const size_t &cam_n)
    : camera_n(cam_n) {}

void SetCamera::execute()
{
     SceneManagerCreator().create_man()->set_camera(camera_n);
}

CountCamera::CountCamera(std::shared_ptr<size_t> &c)
    : count_(c) {}

void CountCamera::execute()
{
    (*count_) =  SceneManagerCreator().create_man()->get_scene()->get_camera().size();
}

