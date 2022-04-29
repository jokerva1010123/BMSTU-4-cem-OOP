#ifndef ITERATOR_BASE_HPP
#define ITERATOR_BASE_HPP

#include <cstddef>
#include <memory>

template <class Type>
class BaseIterator
{
public:
    BaseIterator(Type *);
    BaseIterator(const BaseIterator &);

    virtual ~BaseIterator();

    BaseIterator &operator=(const BaseIterator &);

    BaseIterator &operator++();
    BaseIterator operator++(int);

    BaseIterator &operator--();
    BaseIterator operator--(int);

    ptrdiff_t operator-(const BaseIterator &);

    bool operator==(const BaseIterator &);
    bool operator!=(const BaseIterator &);

protected:
    Type *cur_point;//std::weak_ptr<Type[]> cur_point; // TODO
};

template <class Type>
BaseIterator<Type>::BaseIterator(Type *cur_point)
{
    this->cur_point = cur_point;
}

template <class Type>
BaseIterator<Type>::BaseIterator(const BaseIterator &other)
{
    this->cur_point = other.cur_point;
}

template <class Type>
BaseIterator<Type>::~BaseIterator()
{
    this->cur_point = nullptr;
}

template <class Type>
BaseIterator<Type> &BaseIterator<Type>::operator=(const BaseIterator &rhs)
{
    if (this != &rhs)
    {
        this->cur_point = rhs.cur_point;
    }

    return *this;
}

template <class Type>
BaseIterator<Type> &BaseIterator<Type>::operator++()
{
    ++this->cur_point;
    return *this;
}

template <class Type>
BaseIterator<Type> BaseIterator<Type>::operator++(int)
{
    BaseIterator temp(*this);
    this->operator++();
    return temp;
}

template <class Type>
BaseIterator<Type> &BaseIterator<Type>::operator--()
{
    --this->cur_point;
    return *this;
}

template <class Type>
BaseIterator<Type> BaseIterator<Type>::operator--(int)
{
    BaseIterator temp(*this);
    this->operator--();
    return temp;
}

template <class Type>
ptrdiff_t BaseIterator<Type>::operator-(const BaseIterator<Type> &rhs)
{
    return this->cur_point - rhs.cur_point;
}

template <class Type>
bool BaseIterator<Type>::operator==(const BaseIterator &rhs)
{
    return this->cur_point == rhs.cur_point;
}

template <class Type>
bool BaseIterator<Type>::operator!=(const BaseIterator &rhs)
{
    return this->cur_point != rhs.cur_point;
}

#endif
