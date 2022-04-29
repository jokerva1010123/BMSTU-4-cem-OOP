#include <memory>
#include "director_model.h"

void ModelDirector::set_builer(std::shared_ptr<BuilderModel> b)
{
    builder_ = std::move(b);
}

std::shared_ptr<Model> ModelDirector::build(const std::vector<Point> &p, const std::vector<Link> &l)
{
    builder_->build_point(p);
    builder_->build_link(l);

    return builder_->get();
}
