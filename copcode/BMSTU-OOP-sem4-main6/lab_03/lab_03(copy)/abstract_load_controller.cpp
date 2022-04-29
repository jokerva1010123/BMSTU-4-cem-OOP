#include "abstract_load_controller.h"

void AbstractLoadController::set_loader(std::shared_ptr<BaseLoader> l)
{
    loader = std::move(l);
}
