#include "errors.hpp"

#include "load_scene_controller.h"

std::shared_ptr<Object> LoadSceneController::load(std::string &name)
{
    try
    {
        loader->open(name);

    } catch (std::exception &e)
    {
        time_t time_ = time(NULL);
        throw FileOpenError(__FILE__,
                            typeid(*this).name(),
                            __LINE__,
                            ctime(&time_));
    }

    std::shared_ptr<Object> s;

    try
    {
        s = loader->load(builder);
    } catch (std::exception &e)
    {
        time_t time_ = time(NULL);
        throw FileFormatError(__FILE__,
                              typeid(*this).name(),
                              __LINE__,
                              ctime(&time_));
    }

    loader->close();

    return s;
}
