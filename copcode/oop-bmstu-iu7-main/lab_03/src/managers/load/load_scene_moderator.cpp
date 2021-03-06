//
// Created by amunra23 on 22.05.2021.
//

#include "../../../inc/managers/load/load_scene_moderator.h"
#include "../../inc/exceptions.h"


LoadSceneModerator::LoadSceneModerator(std::shared_ptr<BaseLoaderScene> loader) : _builder(new BuilderScene)
{
//    _builder = new (BuilderModel);
    _loader = loader;
}

std::shared_ptr<Object> LoadSceneModerator::load(std::string &file_name)
{
    try
    {
        _loader->open(file_name);
    }
    catch (SourceException &error)
    {
        std::string msg = "Error : Open file";
        throw SourceException(msg);
    }

    std::shared_ptr<Object> scene;

    try
    {
        scene = _loader->load(_builder);
    }
    catch (std::exception &error)
    {
        std::string msg = "Error : Read model";
        throw SourceException(msg);
    }

    _loader->close();

    return scene;
}





