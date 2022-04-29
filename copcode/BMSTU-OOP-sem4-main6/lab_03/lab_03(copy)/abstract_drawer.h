#ifndef ABSTRACT_DRAWER_H
#define ABSTRACT_DRAWER_H


#include "point.h"

class AbstractDrawer {
public:
    AbstractDrawer() = default;
    virtual ~AbstractDrawer() = default;
    virtual void drawline(const Point &p1, const Point &p2) = 0;
    virtual void clear_scene() = 0;
};


#endif // ABSTRACT_DRAWER_H


