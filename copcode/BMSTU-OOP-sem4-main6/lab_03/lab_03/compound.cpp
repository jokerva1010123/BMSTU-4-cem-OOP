#include "compound.h"


Compound::Compound(std::vector<Point> &p, std::vector<Link> &l)
    : center_{}, point_(p), link_(l) {}

Compound::Compound(Point &c, std::vector<Point> &p, std::vector<Link> &l)
    : center_(c), point_(p), link_(l) {}

void Compound::add_point(const Point &p)
{
    point_.push_back(p);
}

void Compound::add_link(const Link &l)
{
    link_.push_back(l);
}

const Point &Compound::get_center() const
{
    return center_;
}

const std::vector<Point> &Compound::get_point() const
{
    return point_;
}

const std::vector<Link> &Compound::get_link() const
{
    return link_;
}

void Compound::reform(const Point &m,
                      const Point &s,
                      const Point &t)
{
    center_.move(m.get_x(), m.get_y(), m.get_z());

    for (auto &p : point_)
    {
        p.scale(s.get_x(), s.get_y(), s.get_z());
        p.turn(t.get_x(), t.get_y(), t.get_z());
    }
}
