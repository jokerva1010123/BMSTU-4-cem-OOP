#ifndef ITERATOR_CONST_HPP
#define ITERATOR_CONST_HPP

template <class Type>
class VectorBase;
template <class Type>
class MatrixBase;

#include "iterator_base.hpp"

template <class Type>
class ConstIterator : public BaseIterator<Type>
{
public:
    friend class VectorBase<Type>;
    friend class MatrixBase<Type>;

    ConstIterator(Type *);
    ConstIterator(const ConstIterator &);

    const Type &operator*();
    const Type *operator->();

};

template <class Type>
ConstIterator<Type>::ConstIterator(Type *cur_point)
    : BaseIterator<Type>(cur_point) {}

template <class Type>
ConstIterator<Type>::ConstIterator(const ConstIterator &other)
    : BaseIterator<Type>(other.cur_point) {}

template <class Type>
const Type &ConstIterator<Type>::operator*()
{
    return *this->cur_point;
}

template <class Type>
const Type *ConstIterator<Type>::operator->()
{
    return this->cur_point;
}

#endif
