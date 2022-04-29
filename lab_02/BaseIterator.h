#ifndef _BASEITERATOR_H_
#define _BASEITERATOR_H_

#include <cstdlib>

class BaseIterator
{
    public:
        BaseIterator();
        BaseIterator(const BaseIterator &iterator);
        ~BaseIterator();

    protected:
        size_t index = 0;
        size_t size = 0;
};

#endif
