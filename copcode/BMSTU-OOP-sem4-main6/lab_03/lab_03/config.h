#ifndef CONFIG_H
#define CONFIG_H

#include <utility>
#include <string>
#include <memory>
#include <libconfig.h++>

class AbstractConfig
{
public:
    enum interface
    {
        Qt,
        GTK
    };

    enum stream
    {
        File,
        Base,
    };

    explicit AbstractConfig(std::shared_ptr<std::string> s)
        : stream_(std::move(s)) {}


    virtual void readConfigFile(std::shared_ptr<std::string> s) = 0;

    virtual AbstractConfig::interface what_lib() = 0;

    virtual AbstractConfig::stream get_stream() = 0;

protected:
    std::shared_ptr<std::string> stream_;

};


class ConfigCreator
{
public:
    std::shared_ptr<AbstractConfig> get_config(std::shared_ptr<std::string> s);

private:
    std::shared_ptr<AbstractConfig> config_;

    void create_instance(std::shared_ptr<std::string> &s);

};


class MyConfig: public AbstractConfig
{
public:
    explicit MyConfig(std::shared_ptr<std::string> &s);

    void readConfigFile(std::shared_ptr<std::string> s) override;

    AbstractConfig::interface what_lib() override;

    AbstractConfig::stream get_stream() override;

private:
    std::shared_ptr<libconfig::Config> config_my;

};


#endif // CONFIG_ABSTRACT_H
