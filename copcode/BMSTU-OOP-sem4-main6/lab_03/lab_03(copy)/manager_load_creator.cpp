#include "manager_load_creator.h"

void LoadManagerCreator::create_instance()
{
    static std::shared_ptr<LoadManager> m(new LoadManager());

    manager_ = m;
}

std::shared_ptr<LoadManager> LoadManagerCreator::create_man()
{
    if (manager_ == nullptr)
    {
        create_instance();
    }

    return manager_;
}
