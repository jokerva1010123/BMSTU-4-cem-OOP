#ifndef MANAGER_DRAW_H
#define MANAGER_DRAW_H

#include <memory>
#include "base_drawer.h"
#include "base_manager.h"

#include "camera.h"
#include "point.h"
#include "visitor.hpp"
#include "composite.h"

class DrawManager: public Visitor, public BaseManager
{
public:
    DrawManager() = default;
//    DrawManager(const DrawManager &d) = delete;
//    DrawManager &operator=(const DrawManager &) = delete;

    ~DrawManager() = default;

    void visit(const Camera &c) override;
    void visit(const Composite &c) override;
    void visit(const Model &c) override;

    void set_camera(std::shared_ptr<Camera>);
    void set_drawer(std::shared_ptr<BaseDrawer>);

private:
    std::shared_ptr<BaseDrawer> drawer_;
    std::shared_ptr<Camera> camera_;

    Point proect_point(const Point &p);

};

#endif // MANAGER_DRAW_H
