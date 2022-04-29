#ifndef MANAGER_LOAD_CREATOR_H
#define MANAGER_LOAD_CREATOR_H

#include "manager_load.h"
#include <memory>

class LoadManagerCreator
{
public:
    std::shared_ptr<LoadManager> create_man();

private:
    std::shared_ptr<LoadManager> manager_;

    void create_instance();
};

#endif // MANAGER_LOAD_CREATOR_H
