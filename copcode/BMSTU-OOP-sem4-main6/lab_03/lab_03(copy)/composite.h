#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <cstddef>

#include "model.h"
#include "object.h"
//#include "vector.hpp"

class Composite: public Object
{
public:
    friend class DrawManager;
    Composite() = default;

    explicit Composite(std::shared_ptr<Object> &c);
    explicit Composite(const std::vector<std::shared_ptr<Object>> &v);

    size_t size() const;

    bool add(const std::shared_ptr<Object> &c) override;
    bool remove(const iterator &it) override;

    iterator begin() override;
    iterator end() override;

    bool is_visible() override;
    bool is_composite() const override;

    void reform(const Point &m,
                const Point &s,
                const Point &t) override;
    void accept(std::shared_ptr<Visitor> v) override;

//    std::vector<std::shared_ptr<Object>> &get_object_s();
private:
    std::vector<std::shared_ptr<Object>> object_s;
};

#endif // COMPOSITE_H
