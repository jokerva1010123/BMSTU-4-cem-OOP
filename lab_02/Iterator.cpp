#include "Iterator.h"

template <typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &iter)
{
    this->wIter = iter.wIter;
    this->current_index = iter.current_index;
    this->sz = iter.sz;
}

template <typename Type>
Type Iterator<Type>::get_value()
{
    std::shared_ptr<Type[]> copy = this->wIter.lock();
    Type *result = copy.get() + current_index;
    return result;
}

template <typename Type>
Type &Iterator<Type>::operator *()
{
    return get_value();
}

template <typename Type>
Type *Iterator<Type>::operator ->()
{
    Type* result = get_value();
    return result;
}

template <typename Type>
Iterator<Type>::operator bool()
{
    bool result;
    if (current_index >= sz || sz == 0)
        result = false;
    else result = true;
    return result;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator =(const Iterator<Type> &iter)
{
    wIter = iter.wIter;
    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator+=(size_t count)
{
    this->current_index += count;
    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator+(size_t count) const
{
    Iterator<Type> result_iterator(*this);
    result_iterator += count;
    return result_iterator;
}

template <typename Type>
Iterator<Type> &Iterator<Type>::operator-=(size_t count)
{
    this->current_index -= count;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator-(size_t count) const
{
    Iterator<Type> result_iterator(*this);
    result_iterator -= count;
    return result_iterator;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    ++(*this);
    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator++()
{
    this->current_index++;
    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    ++(*this);
    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator--()
{
    this->current_index--;
    return *this;
}

//Операторы сравнений

template<typename Type>
bool Iterator<Type>::operator==(const Iterator<Type> &another_vector) const
{
    bool result = (this->current_index == another_vector.current_index);
    return result;
}

template<typename Type>
bool Iterator<Type>::operator!=(const Iterator<Type> &another_vector) const
{
    bool result = (this->current_index != another_vector.current_index);
    return result;
}

template<typename Type>
bool Iterator<Type>::operator<(const Iterator<Type> &another_vector) const
{
    bool result = (this->current_index < another_vector.current_index);
    return result;
}

template<typename Type>
bool Iterator<Type>::operator<=(const Iterator<Type> &another_vector) const
{
    bool result = (this->current_index <= another_vector.current_index);
    return result;
}

template<typename Type>
bool Iterator<Type>::operator>(const Iterator<Type> &another_vector) const
{
    bool result = (this->current_index > another_vector.current_index);
    return result;
}

template<typename Type>
bool Iterator<Type>::operator>=(const Iterator<Type> &another_vector) const
{
    bool result = (this->current_index >= another_vector.current_index);
    return result;
}

template<typename Type>
Type &Iterator<Type>::operator[](size_t index)
{
    if (index + this->current_index >= this->vector_size)
    {
        time_t current_time = time(NULL);
        throw OutRangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }
    return *(this + index);
}
