#include <stdio.h>
#include "base_vector.h"

BaseVector::operator bool() const noexcept
{
    return bool(count_elem);
}

size_t BaseVector::get_size() const noexcept
{
    return count_elem;
}

BaseVector::~BaseVector()
{
    count_elem = 0;
}
