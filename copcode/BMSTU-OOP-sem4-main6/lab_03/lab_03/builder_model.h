#ifndef BUILDER_MODEL_H
#define BUILDER_MODEL_H

#include <cstddef>
#include <memory>
#include "base_builder.h"
#include "model.h"

class BuilderModel: public BaseBuilder
{
public:
    BuilderModel() = default;
    ~BuilderModel() = default;

    bool is_build() const override;
    void build() override;

    void build_point(const double &x,
                     const double &y,
                     const double &z);

    void build_link(const size_t &p1, const size_t &p2);

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Model> p_model;
};

#endif // BUILDER_MODEL_H
