#ifndef ITERATOR_H
#define ITERATOR_H

#include "errors.h"
#include "base_iterator.h"
#include <memory>
#include <time.h>

template <typename Type>
class Vector;

template <typename Type>
class Iterator: public std::iterator<std::random_access_iterator_tag, int>, public BaseIterator
{
public:
    Iterator(const Iterator<Type> &iterator) noexcept;
    Iterator(const Vector<Type> &vector) noexcept;

    Type &operator*();
    Type *operator->();
    const Type &operator*() const;
    const Type *operator->() const;
    operator bool() const;

    Iterator<Type> &operator=(const Iterator<Type> &iter) noexcept;

    Iterator<Type> operator-(size_t num) const;
    Iterator<Type> &operator--();
    Iterator<Type> operator--(int);
    Iterator<Type> &operator-=(size_t num);

    Iterator<Type> operator+(size_t num) const;
    Iterator<Type> &operator++();
    Iterator<Type> operator++(int);
    Iterator<Type> &operator+=(size_t num);

    bool operator<(const Iterator<Type> &cmp) const;
    bool operator>(const Iterator<Type> &cmp) const;
    bool operator<=(const Iterator<Type> &cmp) const;
    bool operator>=(const Iterator<Type> &cmp) const;
    bool operator==(const Iterator<Type> &cmp) const;
    bool operator!=(const Iterator<Type> &cmp) const;

//    Type &operator[](const size_t index);  // УБРАТЬ!!!
//    const Type &operator[](const size_t index) const; // УБРАТЬ!!!

private:
    std::weak_ptr<Type[]> ptr;

protected:
    Type &get_current_pointer() const;
    void exception_check(int cur_line) const;
    void validity_check(int cur_line) const;
};

#include "iterator.hpp"

#endif // ITERATOR_H
    
