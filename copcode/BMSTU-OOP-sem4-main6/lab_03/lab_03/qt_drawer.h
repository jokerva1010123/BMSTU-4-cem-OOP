#ifndef QT_DRAWER_H
#define QT_DRAWER_H

#include "base_drawer.h"
#include <QGraphicsScene>

class QTDrawer: public BaseDrawer
{
public:
    QTDrawer() = delete;

    explicit QTDrawer(QGraphicsScene *s);

    QTDrawer(const QTDrawer &d);

    void drawline(const Point &p1, const Point &p2) override;

    void clear_scene() override;

private:
    QGraphicsScene *scene_;
};

#endif // QT_DRAWER_H
