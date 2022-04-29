#ifndef MANAGER_LOAD_H
#define MANAGER_LOAD_H

#include <memory>
#include "abstract_load_controller.h"
#include "base_manager.h"

#include "model.h"
#include "base_loader.h"


class LoadManager: public BaseManager
{
public:
    LoadManager();

    ~LoadManager() = default;

    virtual std::shared_ptr<Object> load(std::string &name);
    virtual void set_loader(std::shared_ptr<AbstractLoadController> l);

private:
    std::shared_ptr<AbstractLoadController> loader_;
};

#endif // MANAGER_LOAD_H
