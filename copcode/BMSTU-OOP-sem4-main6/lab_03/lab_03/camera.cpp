#include "camera.h"

void Camera::moveX(const double &s)
{
    cur_p.set_x(cur_p.get_x() + s);
}

void Camera::moveY(const double &s)
{
    cur_p.set_y(cur_p.get_y() + s);
}

void Camera::moveZ(const double &s)
{
    cur_p.set_z(cur_p.get_z() + s);
}

void Camera::reform(const Point &np, const Point &s, const Point &t)
{
    moveX(np.get_x());
    moveY(np.get_y());
}

void Camera::accept(std::shared_ptr<Visitor> v)
{
    v->visit(*this);
}
