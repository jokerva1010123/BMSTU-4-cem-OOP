#include "load_model_controller.h"
#include "director_model.h"


#include "errors.hpp"

std::shared_ptr<Model> LoadModelController::load(std::string &fname)
{
    try
    {
        loader->open(fname);
    } catch (FileOpenError &error)
    {
        time_t time_ = time(NULL);
        throw FileOpenError(__FILE__,
                            typeid(*this).name(),
                            __LINE__,
                            ctime(&time_));
    }

    std::shared_ptr<Object> m;

    std::vector<Point> points;
    std::vector<Link> links;
    try
    {
        points = loader->load_points();
        links = loader->load_links();
    } catch (std::exception &error)
    {
        time_t time_ = time(NULL);
        throw FileFormatError(__FILE__,
                              typeid(*this).name(),
                              __LINE__,
                              ctime(&time_));
    }

    loader->close();

    ModelDirector director;
    director.set_builer(builder);

    return director.build(points, links);
}
