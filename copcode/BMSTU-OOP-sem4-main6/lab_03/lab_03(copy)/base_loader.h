#ifndef BASE_LOADER_H
#define BASE_LOADER_H

#include "base_builder.h"
#include "errors.hpp"
#include "object.h"

#include <string>
#include <fstream>

class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(std::string &name) = 0;
    virtual void close() = 0;
};

#endif // BASE_LOADER_H
