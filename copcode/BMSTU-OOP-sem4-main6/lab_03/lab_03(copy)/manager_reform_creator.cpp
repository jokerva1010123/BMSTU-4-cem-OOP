#include "manager_reform_creator.h"

void ReformManagerCreator::create_instance()
{
    static std::shared_ptr<ReformManager> m(new ReformManager());

    manager_ = m;
}

std::shared_ptr<ReformManager> ReformManagerCreator::create_man()
{
    if (manager_ == nullptr)
    {
        create_instance();
    }

    return manager_;
}
