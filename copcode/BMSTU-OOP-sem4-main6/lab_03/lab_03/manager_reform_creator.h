#ifndef MANAGER_REFORM_CREATOR_H
#define MANAGER_REFORM_CREATOR_H

#include <memory>
#include"manager_reform.h"

class ReformManagerCreator
{
public:
    std::shared_ptr<ReformManager> create_man();

private:

    std::shared_ptr<ReformManager> manager_;

    void create_instance();


};

#endif // MANAGER_REFORM_CREATOR_H
