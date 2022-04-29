#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <utility>

#include "visitor.hpp"
#include "compound.h"

#include "links.h"

#include "object.h"
#include "point.h"

// Сделать дружбу  с визитером (у меня это дроМенеджер)

class DrawManager;

class Model: public VisibleObject
{
public:
    friend class DrawManager;
    friend class BuilderModel;
    Model()
        : compound_(new Compound) {}

    explicit Model(std::shared_ptr<Compound> c)
        : compound_(std::move(c)) {}

    Model(const Model &m);

    ~Model() override = default;


    void reform(const Point &m,
                const Point &s,
                const Point &t) override;
    void accept(std::shared_ptr<Visitor> v) override;

private:
    std::shared_ptr<Compound> compound_;

};

#endif // MODEL_H
