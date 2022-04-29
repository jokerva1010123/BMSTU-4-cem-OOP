#ifndef COMPOUND_H
#define COMPOUND_H

#include <vector>
#include "links.h"
#include "point.h"



class Compound
{
public:
    Compound() = default;
    Compound(std::vector<Point> &p,
             std::vector<Link> &l);

    Compound(Point &c,
             std::vector<Point> &p,
             std::vector<Link> &l);

    ~Compound() = default;

    void add_point(const Point &p);
    void add_link(const Link &l);

    const Point &get_center() const;
    const std::vector<Point> &get_point() const;
    const std::vector<Link> &get_link() const;

    void reform(const Point &m,
                const Point &s,
                const Point &t);

private:
    Point center_;
    std::vector<Point> point_; // std::vector<Point> point_;
    std::vector<Link> link_;

};

#endif // COMPOUND_H
