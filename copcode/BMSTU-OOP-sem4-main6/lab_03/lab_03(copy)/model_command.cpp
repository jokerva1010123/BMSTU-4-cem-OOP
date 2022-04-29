#include <utility>

#include "model_command.h"
#include "manager_load_creator.h"
#include "manager_reform_creator.h"
#include "manager_scene_creator.h"

MoveModel::MoveModel(const double &x,
                     const double &y,
                     const double &z,
                     const size_t &n)
    : dx(x), dy(y), dz(z), model_n_(n) {}

void MoveModel::execute()
{
    Point move(dx, dy, dz);
    Point scale(1, 1, 1);
    Point turn(0, 0, 0);

    std::shared_ptr<Object> model = SceneManagerCreator().create_man()->get_scene()->get_model().at(model_n_);
    ReformManagerCreator().create_man()->reform_obj(model, move, scale, turn);
}

ScaleModel::ScaleModel(const double &x,
                       const double &y,
                       const double &z,
                       const size_t &n)
    : kx(x), ky(y), kz(z), model_n_(n) {}

void ScaleModel::execute()
{
    Point move(0, 0, 0);
    Point scale(kx, ky, kz);
    Point turn(0, 0, 0);

    std::shared_ptr<Object> model = SceneManagerCreator().create_man()->get_scene()->get_model().at(model_n_);
    ReformManagerCreator().create_man()->reform_obj(model, move, scale, turn);
}

RotateModel::RotateModel(const double &x,
                         const double &y,
                         const double &z,
                         const size_t &n)
    : ox(x), oy(y), oz(z), model_n_(n) {}

void RotateModel::execute()
{
    Point move(0, 0, 0);
    Point scale(1, 1, 1);
    Point turn(ox, oy, oz);

    std::shared_ptr<Object> model = SceneManagerCreator().create_man()->get_scene()->get_model().at(model_n_);
    ReformManagerCreator().create_man()->reform_obj(model, move, scale, turn);
}

ReformModel::ReformModel(const size_t &n,
                         const Point &m,
                         const Point &s,
                         const Point &t)
    : model_n_(n), move(m), scale(s), turn(t) {}

void ReformModel::execute()
{
    std::shared_ptr<Object> model = SceneManagerCreator().create_man()->get_scene()->get_model().at(model_n_);
    ReformManagerCreator().create_man()->reform_obj(model, move, scale, turn);
}

LoadModel::LoadModel(std::string fname)
    : file_name(std::move(fname)) {}

void LoadModel::execute()
{
    auto model = LoadManagerCreator().create_man()->load(file_name);
    SceneManagerCreator().create_man()->get_scene()->add_model(model);
}

AddModel::AddModel(std::shared_ptr<Object> model)
    : model(std::move(model)) {}

void AddModel::execute()
{
     SceneManagerCreator().create_man()->get_scene()->add_model(model);
}

RemoveModel::RemoveModel(const size_t &m)
    : model_n_(m) {}

void RemoveModel::execute()
{
     SceneManagerCreator().create_man()->get_scene()->remove_model(model_n_);
}

CountModel::CountModel(std::shared_ptr<size_t> &count)
    : count_(count) {}

void CountModel::execute()
{
    (*count_) = SceneManagerCreator().create_man()->get_scene()->get_model().size();
}
