#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <utility>

#include "visitor.hpp"
#include "compound.h"

#include "links.h"

#include "object.h"
#include "point.h"

class Model: public VisibleObject
{
public:
    Model()
        : compound_(new Compound) {}

    explicit Model(std::shared_ptr<Compound> c)
        : compound_(std::move(c)) {}

    Model(const Model &m);

    ~Model() override = default;

//    std::unique_ptr<Model> clone();

    const std::shared_ptr<Compound> get_compound() const;

    void add_point(const Point &p);
    void add_link(const Link &l);


    void reform(const Point &m,
                const Point &s,
                const Point &t) override;
    void accept(std::shared_ptr<Visitor> v) override;

private:
    std::shared_ptr<Compound> compound_;

};

#endif // MODEL_H
