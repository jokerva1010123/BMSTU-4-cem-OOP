#ifndef FACADE_H
#define FACADE_H

#include "base_command.h"

class Facade
{
public:
    void execute(BaseCommand &command);
};

#endif // FACADE_H
