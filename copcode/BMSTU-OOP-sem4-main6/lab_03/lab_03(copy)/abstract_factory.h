#ifndef ABSTRACTFABRIC_H
#define ABSTRACTFABRIC_H

#include <memory>
#include "base_drawer.h"

// Абстрактная фабрика - это порождающий паттерн проектирования,
// который решает проблему создания целых семейств связанных
// продуктов, без указания конкретных классов продуктов.
class AbstractFactory
{
public:
    virtual std::unique_ptr<BaseDrawer> create_graphics() = 0; // чистая виртуальная функция
};


#endif // ABSTRACTFABRIC_H
