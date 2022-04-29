#include "base_iterator.h"

BaseIterator::BaseIterator()
{
    index = 0;
    num_elem = 0;
}

BaseIterator::BaseIterator(const BaseIterator& iterator)
{
    index = iterator.index;
    num_elem = iterator.num_elem;
}

BaseIterator::~BaseIterator() {}
