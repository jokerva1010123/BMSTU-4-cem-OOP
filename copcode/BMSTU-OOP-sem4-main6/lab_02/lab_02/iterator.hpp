#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator.h"

template<typename Type>
Type &Iterator<Type>::get_current_pointer() const
{
    std::shared_ptr<Type[]> copied = this->ptr.lock();
    return copied.get() + index;
}

template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &iterator) noexcept
{
    this->ptr = iterator.ptr;
    this->index = iterator.index;
    this->num_elem = iterator.num_elem;
}

template<typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vector) noexcept
{
    this->index = 0;
    this->num_elem = vector.get_size();
    this->ptr = vector.values;
}

template<typename Type>
Type &Iterator<Type>::operator*()
{
    exception_check(__LINE__);
    validity_check(__LINE__);

    return *get_current_pointer();
}

template<typename Type>
const Type &Iterator<Type>::operator*() const
{
    exception_check(__LINE__);
    validity_check(__LINE__);

    return *get_current_pointer();
}

template<typename Type>
Type *Iterator<Type>::operator->()
{
    exception_check(__LINE__);
    validity_check(__LINE__);

    return get_current_pointer();
}

template<typename Type>
const Type *Iterator<Type>::operator->() const
{
    exception_check(__LINE__);
    validity_check(__LINE__);

    return get_current_pointer();
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator=(const Iterator<Type>& iterator) noexcept
{
    ptr = iterator.ptr;
    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator+=(size_t number)
{
    exception_check(__LINE__);
    index += number;

    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator+(size_t number) const
{
    exception_check(__LINE__);
    Iterator<Type> iterator(*this);
    iterator += number;

    return iterator;
}

template <typename Type>
Iterator<Type> &Iterator<Type>::operator-=(size_t number)
{
    exception_check(__LINE__);
    index -= number;

    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator-(size_t number) const
{
    exception_check(__LINE__);
    Iterator<Type> iterator(*this);
    iterator -= number;

    return iterator;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    exception_check(__LINE__);
    ++(*this);

    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator++()
{
    exception_check(__LINE__);
    ++index;

    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    exception_check(__LINE__);
    --(*this);

    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator--()
{
    exception_check(__LINE__);
    --index;

    return *this;
}

template<typename Type>
bool Iterator<Type>::operator<(const Iterator<Type> &cmp) const
{
    exception_check(__LINE__);

    return this->index < cmp.index;
}

template<typename Type>
bool Iterator<Type>::operator<=(const Iterator<Type> &cmp) const
{
    exception_check(__LINE__);

    return this->index <= cmp.index;
}

template<typename Type>
bool Iterator<Type>::operator>(const Iterator<Type> &cmp) const
{
    exception_check(__LINE__);

    return this->index > cmp.index;
}

template<typename Type>
bool Iterator<Type>::operator>=(const Iterator<Type> &cmp) const
{
    exception_check(__LINE__);

    return this->index >= cmp.index;
}

template<typename Type>
bool Iterator<Type>::operator==(const Iterator<Type> &cmp) const
{
    exception_check(__LINE__);

    return this->index == cmp.index;
}

template<typename Type>
bool Iterator<Type>::operator!=(const Iterator<Type> &cmp) const
{
    exception_check(__LINE__);

    return this->index != cmp.index;
}

template<typename Type>
Iterator<Type>::operator bool() const
{
    exception_check(__LINE__);

    if (index >= num_elem || num_elem == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template<typename Type>
void Iterator<Type>::exception_check(int cur_line) const
{
    if (ptr.expired())
    {
        time_t cur_time = time(NULL);
        throw DeleteError(__FILE__, typeid(*this).name(),
                          cur_line, ctime(&cur_time));
    }
}

template<typename Type>
void Iterator<Type>::validity_check(int cur_line) const
{
    if (this->index >= this->num_elem)
    {
        time_t cur_time = time(NULL);
        throw IterError(__FILE__, typeid(*this).name(),
                              cur_line, ctime(&cur_time));
    }
}

#endif // ITERATOR_HPP
//template<typename Type>
//Type &Iterator<Type>::operator[](size_t index) {
//    size_t curLine = __LINE__;
//    exception_check(curLine);

//    time_t currentTime = time(NULL);
//    if (index + this->index >= this->vectorLen)
//        throw IndexError(__FILE__, typeid(*this).name(),
//                                  curLine, ctime(&currentTime));

//    return *(this + index);
//}

//template<typename Type>
//const Type &Iterator<Type>::operator[](size_t index) const {
//    size_t curLine = __LINE__;
//    exception_check(curLine);

//    time_t currentTime = time(NULL);
//    if (index + this->index >= this->vectorLen)
//        throw IndexError(__FILE__, typeid(*this).name(),
//                                  curLine, ctime(&currentTime));

//    return *(this + index);
//}

