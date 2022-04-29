#include "builder_model.h"
#include "errors.hpp"
#include "loader_filemodel.h"

LoaderFileModel::LoaderFileModel()
    : file(std::make_shared<std::ifstream>()) {}




LoaderFileModel::LoaderFileModel(std::shared_ptr<std::ifstream> &f) {
    file = f;
}


std::shared_ptr<Object> LoaderFileModel::load(std::shared_ptr<BuilderModel> b)
{
    b->build();

    size_t count;
    *file >> count;

    for (size_t i = 0; i < count; i++)
    {
        double x, y, z;
        *file >> x >> y >> z;
        b->build_point(x, y, z);
    }

    size_t count1;
    *file >> count1;

    for (size_t i = 0; i < count1; i++)
    {
        size_t pt1, pt2;
        *file >> pt1 >> pt2;
        b->build_link(pt1, pt2);
    }

    return b->get();
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
