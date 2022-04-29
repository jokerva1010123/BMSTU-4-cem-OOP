#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "visitor.hpp"
#include "point.h"
#include <memory>

class Object;

using iterator = std::vector<std::shared_ptr<Object>>::iterator;

class Object
{
public:
    Object() = default;

    virtual ~Object() = default;

    virtual bool add(const std::shared_ptr<Object> &)
    {
        return false;
    }

    virtual bool remove(const iterator &)
    {
        return false;
    }

    virtual iterator begin()
    {
        return iterator();
    }
    virtual iterator end()
    {
        return iterator();
    }

    virtual bool is_visible()
    {
        return false;
    }
    virtual bool is_composite() const
    {
        return false;
    }

    virtual void accept(std::shared_ptr<Visitor> v) = 0;
    virtual void reform(const Point &m,
                        const Point &s,
                        const Point &t) = 0;

};

class VisibleObject: public Object
{
public:
    VisibleObject() = default;

    ~VisibleObject() override = default;

    bool is_visible() override
    {
        return false;
    }
};


class InvisibleObject: public Object
{
public:
    InvisibleObject() = default;

    ~InvisibleObject() override = default;

    bool is_visible() override
    {
        return false;
    }
};

#endif // OBJECT_H
