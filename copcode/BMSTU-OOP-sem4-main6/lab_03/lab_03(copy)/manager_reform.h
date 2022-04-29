#ifndef MANAGER_REFORM_H
#define MANAGER_REFORM_H

#include "object.h"
#include "base_manager.h"

class ReformManager: public BaseManager
{
public:
    ReformManager() = default;

    ~ReformManager() = default;

    void reform_obj(const std::shared_ptr<Object> &o,
                       const Point &m, const Point &s,
                       const Point &t);

    void move_obj(const std::shared_ptr<Object> &o,
                  const double &x, const double &y,
                  const double &z);
    void scale_obj(const std::shared_ptr<Object> &o,
                   const double &x, const double &y,
                   const double &z);
    void turn_obj(const std::shared_ptr<Object> &o,
                  const double &x, const double &y,
                  const double &z);
};

#endif // MANAGER_REFORM_H
