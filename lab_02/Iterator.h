#ifndef ITERATOR_H
#define ITERATOR_H

#include "Exception.h"
#include <memory>
#include <time.h>

template <typename Type>
class Iterator : public std::iterator<std::random_access_iterator_tag, int>
{
    public:
        Iterator(const Iterator<Type> &iter);

        Type &operator*();
        Type *operator->();
        operator bool();

        Iterator<Type> &operator =(const Iterator<Type> &iter);

        Iterator<Type> &operator+=(size_t count);
        Iterator<Type> operator+(size_t count) const;
        Iterator<Type> &operator++();
        Iterator<Type> operator++(int);

        Iterator<Type> &operator-=(size_t count);
        Iterator<Type> operator-(size_t count) const;
        Iterator<Type> &operator--();
        Iterator<Type> operator--(int);

        bool operator==(const Iterator<Type> &another) const;
        bool operator!=(const Iterator<Type> &another) const;

        bool operator<(const Iterator<Type> &another) const;
        bool operator>(const Iterator<Type> &another) const;
        bool operator<=(const Iterator<Type> &another) const;
        bool operator>=(const Iterator<Type> &another) const;

        Type &operator[](const size_t index);
    protected:
        size_t current_index = 0;
        size_t sz = 0;
        Type get_value();
    private:
        std::weak_ptr<Type[]> wIter;
};

#endif // ITERATOR_H
