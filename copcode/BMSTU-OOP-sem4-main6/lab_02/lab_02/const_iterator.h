#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H

#include "errors.h"
#include "base_iterator.h"

#include <memory>
#include <time.h>

template<typename Type>
class Vector;

template<typename Type>
class ConstIterator: public std::iterator<std::random_access_iterator_tag, int>, public BaseIterator
{
public:
    ConstIterator(const ConstIterator<Type> &iterator) noexcept;
    ConstIterator(const Vector<Type> &vector) noexcept;

    const Type &operator*() const;
    const Type *operator->() const;
    operator bool() const;

    ConstIterator<Type> &operator=(const ConstIterator<Type> &iterator) noexcept;

    ConstIterator<Type> &operator-=(size_t number);
    ConstIterator<Type> operator-(size_t number) const;
    ConstIterator<Type> &operator--();
    ConstIterator<Type> operator--(int);

    ConstIterator<Type> &operator+=(size_t number);
    ConstIterator<Type> operator+(size_t number) const;
    ConstIterator<Type> &operator++();
    ConstIterator<Type> operator++(int);

    bool operator<=(const ConstIterator<Type> &cmp) const;
    bool operator<(const ConstIterator<Type> &cmp) const;
    bool operator>=(const ConstIterator<Type> &cmp) const;
    bool operator>(const ConstIterator<Type> &cmp) const;
    bool operator==(const ConstIterator<Type> &cmp) const;
    bool operator!=(const ConstIterator<Type> &cmp) const;

//    const Type &operator[](const size_t index) const; // УБРАТЬ!!!

private:
    std::weak_ptr<Type[]> ptr;

protected:
    Type *get_current_pointer() const;
    void exception_check(int cur_line) const;
    void validity_check(int cur_line) const;
};

#include "const_iterator.hpp"

#endif // CONST_ITERATOR_H
