#include "manager_draw_creator.h"

void DrawManagerCreator::create_instance()
{
    static std::shared_ptr<DrawManager> manager(new DrawManager());

    manager_ = manager;
}


std::shared_ptr<DrawManager> DrawManagerCreator::create_man()
{
    if (manager_ == nullptr)
    {
        create_instance();
    }

    return manager_;
}
