#ifndef BASE_DRAWER_H
#define BASE_DRAWER_H

#include "point.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;

    virtual ~BaseDrawer() = default;

    virtual void drawline(const Point &p1, const Point &p2) = 0;
    virtual void clear_scene() = 0;
};

#endif // BASE_DRAWER_H
