#include "manager_reform.h"

void ReformManager::reform_obj(const std::shared_ptr<Object> &o, const Point &m, const Point &s, const Point &t)
{
    o->reform(m, s, t);
}

void ReformManager::move_obj(const std::shared_ptr<Object> &o, const double &x, const double &y, const double &z)
{
    Point m(x, y, z);
    Point s(1, 1, 1);
    Point t(0, 0, 0);

    o->reform(m, s, t);
}

void ReformManager::scale_obj(const std::shared_ptr<Object> &o, const double &x, const double &y, const double &z)
{
    Point m(0, 0, 0);
    Point s(x, y, z);
    Point t(0, 0, 0);

    o->reform(m, s, t);
}

void ReformManager::turn_obj(const std::shared_ptr<Object> &o, const double &x, const double &y, const double &z)
{
    Point m(0, 0, 0);
    Point s(1, 1, 1);
    Point t(x, y, z);

    o->reform(m, s, t);
}

