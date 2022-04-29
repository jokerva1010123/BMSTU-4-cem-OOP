#include "loader_filescene.h"

#include "builder_scene.h"
#include "errors.hpp"
#include "loader_filecamera.h"
#include "loader_filemodel.h"

#include "builder_camera.h"

LoaderFileScene::LoaderFileScene()
    : file(std::make_shared<std::ifstream>()) {}


std::shared_ptr<Object> LoaderFileScene::load(const std::shared_ptr<BuilderScene> &b)
{
    b->build();

    load_model(b);

    load_camera(b);

    return b->get();
}




void LoaderFileScene::open(std::string &name)
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

void LoaderFileScene::close()
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

void LoaderFileScene::load_model(std::shared_ptr<BuilderScene> b)
{
    size_t count;
    *file >> count;

    auto mb = std::make_shared<BuilderModel>();

    for (size_t i = 0; i < count; ++i)
    {
        b->build_model(LoaderFileModel(file).load(mb));
    }
}


void LoaderFileScene::load_camera(std::shared_ptr<BuilderScene> b)
{
    size_t count;
    *file >> count;

    auto cb = std::make_shared<BuilderCamera>();

    for (size_t i = 0; i < count; ++i)
    {
        auto camera = std::dynamic_pointer_cast<Camera>(LoaderFileCamera(file).load(cb));
        b->build_camera(camera);
    }
}
