#ifndef BASE_LOADERSCENE_H
#define BASE_LOADERSCENE_H

#include "builder_scene.h"
#include "base_loader.h"
#include "object.h"

class LoaderBaseScene: public BaseLoader
{
public:
    virtual std::shared_ptr<Object> load(const std::shared_ptr<BuilderScene> &b) = 0;

protected:
    virtual void load_model(std::shared_ptr<BuilderScene> b) = 0;
    virtual void load_camera(std::shared_ptr<BuilderScene> b) = 0;

};

#endif // BASE_LOADERSCENE_H
