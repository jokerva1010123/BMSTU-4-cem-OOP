#include "config.h"
#include "errors.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>

void ConfigCreator::create_instance(std::shared_ptr<std::string> &s)
{
    std::shared_ptr<AbstractConfig> c(new MyConfig(s));
    config = c;
}

std::shared_ptr<AbstractConfig> ConfigCreator::get_config(std::shared_ptr<std::string> s)
{
    if (config == nullptr)
    {
        create_instance(s);
    }
    else if (s)
    {
        config->readConfigFile(s);
    }

    return config;
}

MyConfig::MyConfig(std::shared_ptr<std::string> &s)
    : AbstractConfig(s) {}

void MyConfig::readConfigFile(std::shared_ptr<std::string> filename)
{
    config_ = std::make_shared<libconfig::Config>();

    try
    {
        const char *ss;
        if (stream)
            ss = stream->c_str();
        else
            ss = filename->c_str();
        config_->readFile(ss);
    } catch (libconfig::FileIOException &error)
    {
        time_t time_ = time(NULL);
        throw FileOpenError(__FILE__,
                            typeid(*this).name(),
                            __LINE__,
                            ctime(&time_));
    } catch (libconfig::ParseException &error)
    {
        time_t time_ = time(NULL);
        throw FileOpenError(__FILE__,
                            typeid(*this).name(),
                            __LINE__,
                            ctime(&time_));
    }
}

AbstractConfig::interface MyConfig::what_lib()
{
    if (config_ != nullptr)
    {
        readConfigFile(std::make_shared<std::string>("config.cfg"));
    }
    std::string interface_;
    auto &r = config_->getRoot();

    try
    {
        const auto &i = r["graphics"];

        if (!i.lookupValue("frame", interface_))
        {
            interface_ = "qt";
        }
    } catch (libconfig::SettingNotFoundException &error)
    {
        return Qt;

    }

    return Qt;
}
