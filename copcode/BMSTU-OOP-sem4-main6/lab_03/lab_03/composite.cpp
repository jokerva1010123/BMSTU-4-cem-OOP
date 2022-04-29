#include "composite.h"

Composite::Composite(std::shared_ptr<Object> &c)
{
    object_s.push_back(c);
}

Composite::Composite(const std::vector<std::shared_ptr<Object>> &v)
{
    object_s = v;
}

bool Composite::add(const std::shared_ptr<Object> &c)
{
    object_s.push_back(c);

    return true;
}

bool Composite::remove(const iterator &it)
{
    object_s.erase(it);

    return true;
}

iterator Composite::begin()
{
    return object_s.begin();
}

iterator Composite::end()
{
    return object_s.end();
}

bool Composite::is_composite() const
{
    return true;
}

bool Composite::is_visible()
{
    return false;
}

size_t Composite::size() const
{
    return object_s.size();
}

void Composite::reform(const Point &m,
                       const Point &s,
                       const Point &t)
{
    for (const auto &e : object_s)
    {
        e->reform(m, s, t);
    }
}

void Composite::accept(std::shared_ptr<Visitor> v)
{
    for (const auto &e : object_s)
    {
        e->accept(v);
    }
}

std::vector<std::shared_ptr<Object>> &Composite::get_object_s()
{
    return object_s;
}
