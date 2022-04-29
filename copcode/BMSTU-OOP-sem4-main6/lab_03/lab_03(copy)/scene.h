#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "composite.h"

class Scene: public Object
{
public:
    friend class DrawManager;
    Scene() : model_(new Composite) {}

    ~Scene() override = default;

    void add(const std::shared_ptr<Object> &m) override;
    void remove(const size_t number) override;


protected:
    std::shared_ptr<Composite> object_;

private:
    void accept(std::shared_ptr<Visitor> v) override {}
    void reform(const Point &m,
                const Point &s,
                const Point &t) override {}
};

#endif // SCENE_H
