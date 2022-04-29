#ifndef DIRECTOR_MODEL_H
#define DIRECTOR_MODEL_H

#include <memory>

#include "builder_model.h"
#include "model.h"
#include "loader_filemodel.h"

class ModelDirector
{
public:
    std::shared_ptr<Model> build(const std::vector<Point> &p,
                                 const std::vector<Link> &l);
    void set_builer(std::shared_ptr<BuilderModel> b);

private:
    std::shared_ptr<BuilderModel> builder_;
};

#endif // DIRECTOR_MODEL_H

