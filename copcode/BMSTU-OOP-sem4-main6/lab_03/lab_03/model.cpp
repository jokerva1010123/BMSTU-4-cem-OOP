#include <memory>
#include "model.h"


Model::Model(const Model &m)
{
    compound_ = m.get_compound();
}

//std::unique_ptr<Model> Model::clone()
//{
//    return std::make_unique<Model>(*this);
//}

void Model::add_point(const Point &p)
{
    compound_->add_point(p);
}

void Model::add_link(const Link &l)
{
    compound_->add_link(l);
}

void Model::accept(std::shared_ptr<Visitor> v)
{
    v->visit(*this);
}

void Model::reform(const Point &m, const Point &s, const Point &t)
{
    compound_->reform(m, s, t);
}

const std::shared_ptr<Compound> Model::get_compound() const
{
    return compound_;
}
