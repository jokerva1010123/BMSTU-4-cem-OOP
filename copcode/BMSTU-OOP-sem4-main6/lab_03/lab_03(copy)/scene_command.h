#ifndef SCENE_COMMAND_H
#define SCENE_COMMAND_H

#include <memory>

#include "base_drawer.h"
#include "base_command.h"


class BaseSceneCommand : public BaseCommand {};


class DrawScene : public  BaseSceneCommand {
public:
    explicit DrawScene(std::shared_ptr<BaseDrawer> d);

    DrawScene() = delete;

    ~DrawScene() override = default;

    void execute() override;

private:
    std::shared_ptr<BaseDrawer> drawer_;
};

class LoadScene : public  BaseSceneCommand {
public:
    explicit LoadScene(std::string fn);

    LoadScene() = delete;

    ~LoadScene() override = default;

    void execute() override;

private:
    std::string filename_;
};

class ExportScene: public BaseSceneCommand
{
public:
    explicit ExportScene(std::string filename);

    ExportScene() = delete;
    ~ExportScene() override = default;

    void execute() override;

private:
    std::string filename_;
};


#endif // SCENE_COMMAND_H
