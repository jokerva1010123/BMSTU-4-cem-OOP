#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H

#include <cstddef>

class BaseVector
{
public:
    BaseVector(size_t count_elem = 0): count_elem(count_elem) { }

    virtual operator bool() const noexcept;

    virtual size_t get_size() const noexcept;

    virtual ~BaseVector() = 0;

protected:
    size_t count_elem = 0;
};

#endif // BASE_VECTOR_H
