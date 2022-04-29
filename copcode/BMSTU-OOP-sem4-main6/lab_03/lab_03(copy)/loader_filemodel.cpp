#include "builder_model.h"
#include "errors.hpp"
#include "loader_filemodel.h"
#include "director_model.h"

#include "errors.hpp"

LoaderFileModel::LoaderFileModel()
    : file(std::make_shared<std::ifstream>()) {}


LoaderFileModel::LoaderFileModel(std::shared_ptr<std::ifstream> &f)
{
    file = f;
}

void LoaderFileModel::open(std::string &name)
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

void LoaderFileModel::close()
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
    } catch (std::ifstream::failure &e)
    {
        time_t time_ = time(NULL);
        throw FileOpenError(__FILE__,
                            typeid(*this).name(),
                            __LINE__,
                            ctime(&time_));
    }
}


std::vector<Point> LoaderFileModel::load_points()
{
    time_t t_time = time(NULL);

    if (!file)
    {
        throw FileOpenError(__FILE__,
                            typeid(*this).name(),
                            __LINE__,
                            ctime(&t_time));
    }

    size_t n_points = 0;
    file >> n_points;

    if (n_points < 1)
    {
        throw FileFormatError(__FILE__,
                              typeid(*this).name(),
                              __LINE__,
                              ctime(&t_time));
    }

    std::vector<Point> points(n_points, Point(0, 0, 0));

    for (size_t i = 0; i < n_points; ++i)
    {
        if (!(file >> points[i]))
        {
            throw FileFormatError(__FILE__,
                                  typeid(*this).name(),
                                  __LINE__,
                                  ctime(&t_time));
        }
    }

    return points;
}

std::vector<Link> LoaderFileModel::load_links()
{
    time_t t_time = time(NULL);

    if (!file)
    {
        throw FileOpenError(__FILE__,
                typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    size_t n_links = 0;
    file >> n_links;

    if (n_links < 1)
    {
        throw FileFormatError(__FILE__,
                              typeid(*this).name(),
                              __LINE__, ctime(&t_time));
    }

    std::vector<Link> links(n_links, Link());

    for (size_t i = 0; i < n_links; ++i)
    {
        if (!(file >> links[i]))
        {
            throw FileFormatError(__FILE__,
                                  typeid(*this).name(),
                                  __LINE__, ctime(&t_time));
        }
    }

    return links;
}
