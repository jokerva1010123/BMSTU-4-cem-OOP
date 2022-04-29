#ifndef LOADER_BASE_CAMERA_H
#define LOADER_BASE_CAMERA_H

#include "base_loader.h"
#include "builder_camera.h"

class LoaderBaseCamera: public BaseLoader
{
public:
    virtual Point load_pos() = 0;

#endif // LOADER_BASE_CAMERA_H
