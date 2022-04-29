#ifndef QT_FACTORY_H
#define QT_FACTORY_H

#include <memory>
#include "abstract_factory.h"
#include "qt_drawer.h"
#include "config.h"

class QTFactory: public AbstractFactory
{
public:
    explicit QTFactory(QGraphicsScene *scene)
        : scene_(scene) {}

    std::unique_ptr<BaseDrawer> create_graphics() override
    {
        return std::unique_ptr<BaseDrawer>(new QTDrawer(scene_));
    }

private:
    QGraphicsScene *scene_;
    std::shared_ptr<AbstractConfig> config_;
};

#endif // QT_FACTORY_H
