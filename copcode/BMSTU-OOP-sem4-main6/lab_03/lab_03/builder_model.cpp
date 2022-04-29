#include "builder_model.h"

void BuilderModel::build()
{
    p_model = std::make_shared<Model>();
}

void BuilderModel::build_point(const double &x,
                               const double &y,
                               const double &z)
{
    if (is_build())
    {
        Point p(x, y, z);

        p_model->add_point(p);
    }
}

void BuilderModel::build_link(const size_t &p1,
                              const size_t &p2)
{
    if (is_build())
    {
        Link l(p1, p2);
        p_model->add_link(l);
    }
}

std::shared_ptr<Object> BuilderModel::get()
{
    return p_model;
}

bool BuilderModel::is_build() const
{
    return (p_model != nullptr);
}
