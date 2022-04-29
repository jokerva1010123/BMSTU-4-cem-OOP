#ifndef MANAGER_DRAW_CREATOR_H
#define MANAGER_DRAW_CREATOR_H

#include "memory"
#include "manager_draw.h"

class DrawManagerCreator
{
public:
    std::shared_ptr<DrawManager> create_man();

private:
    std::shared_ptr<DrawManager> manager_;
    void create_instance();
};

#endif // MANAGER_DRAW_CREATOR_H
