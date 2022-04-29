#ifndef LOADER_FILESCENE_H
#define LOADER_FILESCENE_H

#include "base_loaderscene.h"

class LoaderFileScene: public LoaderBaseScene
{
public:
    LoaderFileScene();
    ~LoaderFileScene() override = default;

    std::shared_ptr<Object> load(const std::shared_ptr<BuilderScene>& builder) override;

    void open(std::string &name) override;
    void close() override;

protected:
    std::shared_ptr<std::ifstream> file;

    void load_model(std::shared_ptr<BuilderScene> b) override;
    void load_camera(std::shared_ptr<BuilderScene> b) override;

};

#endif // LOADER_FILESCENE_H
