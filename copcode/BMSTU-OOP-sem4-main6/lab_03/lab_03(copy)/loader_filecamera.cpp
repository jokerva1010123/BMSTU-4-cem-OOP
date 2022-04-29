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

Point LoaderFileCamera::load_pos()
{
    time_t t_time = time(NULL);

    if (!file)
    {
        throw FileOpenError(__FILE__,
                typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    Point p(3, 0);

    if (!(file >> p))
    {
        throw FileFormatError(__FILE__,
                              typeid(*this).name(),
                              __LINE__, ctime(&t_time));
    }


    return p;
}

