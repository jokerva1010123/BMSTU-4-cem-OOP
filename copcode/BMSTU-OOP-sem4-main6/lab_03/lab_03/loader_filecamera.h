#ifndef LOADER_FILECAMERA_H
#define LOADER_FILECAMERA_H

#include "base_loadercamera.h"

class LoaderFileCamera: public LoaderBaseCamera
{
public:
    LoaderFileCamera();

    explicit LoaderFileCamera(std::shared_ptr<std::ifstream> &f);

    ~LoaderFileCamera() override = default;

    std::shared_ptr<Object> load(std::shared_ptr<BuilderCamera> &b) override;


    void open(std::string &name) override;
    void close() override;

protected:
    std::shared_ptr<std::ifstream> file;
};

#endif // LOADER_FILECAMERA_H
