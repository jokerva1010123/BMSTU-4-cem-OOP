#ifndef BASE_BUILDER_H
#define BASE_BUILDER_H

#include "object.h"

class BaseBuilder
{
public:
    BaseBuilder() = default;
    ~BaseBuilder() = default;

    virtual bool is_build() const = 0;
    virtual void build() = 0;

    virtual std::shared_ptr<Object> get() = 0;
};

#endif // BASE_BUILDER_H
