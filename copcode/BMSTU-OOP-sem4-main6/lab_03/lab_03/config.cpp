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
    config_ = c;
}

std::shared_ptr<AbstractConfig> ConfigCreator::get_config(std::shared_ptr<std::string> s)
{
    if (config_ == nullptr)
    {
        create_instance(s);
    }
    else if (s)
    {
        config_->readConfigFile(s);
    }

    return config_;
}


MyConfig::MyConfig(std::shared_ptr<std::string> &s)
    : AbstractConfig(s) {}

void MyConfig::readConfigFile(std::shared_ptr<std::string> filename)
{
    config_my = std::make_shared<libconfig::Config>();

    try
    {
        const char *ss;
        if (stream_)
            ss = stream_->c_str();
        else
            ss = filename->c_str();
        config_my->readFile(ss);
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
    if (config_my != nullptr)
    {
        readConfigFile(std::make_shared<std::string>("config.cfg"));
    }
    std::string interface_;
    auto &r = config_my->getRoot();

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

AbstractConfig::stream MyConfig::get_stream()
{
    if (config_my != nullptr)
    {
        readConfigFile(std::make_shared<std::string>("config.cfg"));
    }
    std::string interface_;
    auto &r = config_my->getRoot();

    try
    {
        const auto &i = r["storage"];

        if (!i.lookupValue("load_source", interface_))
        {
            interface_ = "file";
        }
    } catch (libconfig::SettingNotFoundException &error)
    {
        return File;

    }

    return File;
}
