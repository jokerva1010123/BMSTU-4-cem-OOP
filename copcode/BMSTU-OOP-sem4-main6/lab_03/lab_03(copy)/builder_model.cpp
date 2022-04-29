#include "builder_model.h"

void BuilderModel::build()
{
    p_model = std::make_shared<Model>();
}

void BuilderModel::build_point(const std::vector<Point> &p)
{
    p_model->compound_->get_point() = p;
}

void BuilderModel::build_link(const std::vector<Link> &l)
{
    p_model->compound_->get_link() = l;
}

std::shared_ptr<Object> BuilderModel::get()
{
    return p_model;
}

bool BuilderModel::is_build() const
{
    return (p_model != nullptr);
}
