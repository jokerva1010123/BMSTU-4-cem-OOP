#include "qt_drawer.h"

QTDrawer::QTDrawer(QGraphicsScene *s)
    : scene_(s) {}

QTDrawer::QTDrawer(const QTDrawer &d)
    : scene_(d.scene_) {}

void QTDrawer::clear_scene()
{
    scene_->clear();
}

void QTDrawer::drawline(const Point &p1, const Point &p2)
{
    scene_->addLine(p1.get_x(), p1.get_y(),
                    p2.get_x(), p2.get_y());
}
