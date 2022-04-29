#ifndef DIRECTOR_CAMERA_H
#define DIRECTOR_CAMERA_H

#include <memory>

#include "builder_camera.h".h"
#include "model.h"
#include "loader_filecamera.h".h"

class CameraDirector
{
public:
    std::shared_ptr<Camera> build(const Point p);
    void set_builer(std::shared_ptr<BuilderCamera> b);

private:
    std::shared_ptr<BuilderCamera> builder_;
};


#endif // DIRECTOR_CAMERA_H
