#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"

#include "visitor.hpp"
#include "builder_camera.h"

class Camera: public InvisibleObject
{
public:
    friend class DrawManager;
    friend class BuilderCamera;

    Camera() = default;

    explicit Camera(const Point &p)
        : cur_p(p) {}

    ~Camera() override = default;

    void reform(const Point &p,
                const Point &t,
                const Point &s) override;
    void accept(std::shared_ptr<Visitor> v) override;

//    Point get_pos()
//    {
//        return cur_p;
//    }

//    void moveX(const double &s);
//    void moveY(const double &s);
//    void moveZ(const double &s);

private:
    Point cur_p;
};

#endif // CAMERA_H
