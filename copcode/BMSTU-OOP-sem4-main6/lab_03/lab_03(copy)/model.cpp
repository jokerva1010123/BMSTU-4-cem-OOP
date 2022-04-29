#include <memory>
#include "model.h"


Model::Model(const Model &m)
{
    compound_ = m.compound_;
}


void Model::accept(std::shared_ptr<Visitor> v)
{
    v->visit(*this);
}

void Model::reform(const Point &m, const Point &s, const Point &t)
{
    compound_->reform(m, s, t);
}

//const std::shared_ptr<Compound> Model::get_compound() const
//{
//    return compound_;
//}
