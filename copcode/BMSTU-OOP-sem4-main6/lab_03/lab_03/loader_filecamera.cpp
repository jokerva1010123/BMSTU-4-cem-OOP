#include "errors.hpp"
#include "builder_scene.h"
#include "loader_filecamera.h"

LoaderFileCamera::LoaderFileCamera()
    : file(std::make_shared<std::ifstream>()) {}

LoaderFileCamera::LoaderFileCamera(std::shared_ptr<std::ifstream> &f)
{
    file = f;
}

void LoaderFileCamera::open(std::string &name)
{
    if (!file)
    {
        time_t time_ = time(NULL);
        throw FileOpenError(__FILE__,
                            typeid(*this).name(),
                            __LINE__,
                            ctime(&time_));
    }

    file->open(name);

    if (!file)
    {
        time_t time_ = time(NULL);
        throw FileOpenError(__FILE__,
                            typeid(*this).name(),
                            __LINE__,
                            ctime(&time_));
    }
}


void LoaderFileCamera::close()
{
    if (!file)
    {
        time_t time_ = time(NULL);
        throw FileOpenError(__FILE__,
                            typeid(*this).name(),
                            __LINE__,
                            ctime(&time_));
    }

    try
    {
        file->close();
    } catch (std::exception &e)
    {
        time_t time_ = time(NULL);
        throw FileOpenError(__FILE__,
                            typeid(*this).name(),
                            __LINE__,
                            ctime(&time_));
    }
}

std::shared_ptr<Object> LoaderFileCamera::load(std::shared_ptr<BuilderCamera> &b)
{
    b->build();

    double x, y, z;

    *file >> x >> y >> z;

    b->build_pos(x, y, z);
    return b->get();
}
