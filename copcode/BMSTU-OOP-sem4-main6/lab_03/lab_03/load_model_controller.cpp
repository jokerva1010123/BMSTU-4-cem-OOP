#include "load_model_controller.h"

#include "errors.hpp"

std::shared_ptr<Object> LoadModelController::load(std::string &fname)
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

    try
    {
        m = loader->load(builder);
    } catch (std::exception &error)
    {
        time_t time_ = time(NULL);
        throw FileFormatError(__FILE__,
                              typeid(*this).name(),
                              __LINE__,
                              ctime(&time_));
    }

    loader->close();

    return m;
}
