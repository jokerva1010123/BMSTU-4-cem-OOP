#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_base.hpp"

template <class Type>
class VectorBase;
template <class Type>
class MatrixBase;

template <class Type>
class Iterator : public BaseIterator<Type>
{
public:
    friend class VectorBase<Type>;
    friend class MatrixBase<Type>;

    Iterator(Type *);
    Iterator(const Iterator &);

    Type &operator*();
    Type *operator->();
};

template <class Type>
Iterator<Type>::Iterator(Type *cur_point)
    : BaseIterator<Type>(cur_point) {}

template <class Type>
Iterator<Type>::Iterator(const Iterator &other) : BaseIterator<Type>(other.cur_point)
{
}

template <class Type>
Type &Iterator<Type>::operator*()
{
    return *this->cur_point;
}

template <class Type>
Type *Iterator<Type>::operator->()
{
    return this->cur_point;
}

//template<typename Type>
//Type &Iterator<Type>::get() const
//{
//    return this->cur_point;
//}
#endif
