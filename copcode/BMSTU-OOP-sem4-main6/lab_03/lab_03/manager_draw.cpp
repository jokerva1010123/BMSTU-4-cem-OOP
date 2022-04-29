#include "manager_draw.h"
#include <utility>


void DrawManager::set_drawer(std::shared_ptr<BaseDrawer> d)
{
    drawer_ = std::move(d);
}

void DrawManager::set_camera(std::shared_ptr<Camera> c)
{
    camera_ = std::move(c);
}

void DrawManager::visit(const Model &m)
{
    auto p = m.get_compound()->get_point();

    auto center = m.get_compound()->get_center();

    for (auto l : m.get_compound()->get_link())
    {
        drawer_->drawline(
                proect_point(p.at(l.get_p1()).add_to(center)),
                proect_point(p.at(l.get_p2())).add_to(center));
    }
}

Point DrawManager::proect_point(const Point &p)
{
    Point np(p);
    Point cp(camera_->get_pos());
    np.set_x(np.get_x() + cp.get_x());
    np.set_y(np.get_y() + cp.get_y());

    return np;
}

void DrawManager::visit(const Camera &camera){}

void DrawManager::visit(const Composite &composite){}
