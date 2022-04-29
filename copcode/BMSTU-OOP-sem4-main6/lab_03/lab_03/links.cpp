#include "links.h"

Link::Link(const size_t &p1, const size_t &p2)
    : p1_i(p1), p2_i(p2) {}

size_t Link::get_p1() const
{
    return p1_i;
}

size_t Link::get_p2() const
{
    return p2_i;
}


void Link::set_p1(const size_t &p1)
{
    p1_i = p1;
}

void Link::set_p2(const size_t &p2)
{
    p2_i = p2;
}
