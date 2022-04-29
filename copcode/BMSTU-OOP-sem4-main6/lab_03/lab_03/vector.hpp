#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <istream>
#include <iterator>
#include <memory>
#include <ostream>

#include "errors.hpp"

template <typename Type>
class BaseVector
{
public:
    BaseVector() = default;
    ~BaseVector() = default;

    virtual void clean_vector() = 0;
    virtual size_t get_size() const = 0;
//    virtual bool is_empty() const = 0;

protected:
    size_t size = 0;
};



template <typename Type>
class Vector: public BaseVector<Type>
{
private:
    template <typename P, typename R, typename VecPtr>
    class Iterator;

public:
    using iterator = Iterator<std::shared_ptr<Type>, Type &,
                               Vector<Type> *>;
    using const_iterator = Iterator<const std::shared_ptr<Type>,
                    const Type &, const Vector<Type> *>;

    Vector();
    Vector(size_t size, const Type &array);
    Vector(std::initializer_list<Type> elem);
    Vector(const Vector<Type> &vector);
    Vector(Vector<Type> &&vector) noexcept;


    Vector<Type> &operator=(const Vector<Type> &vec);
    Vector<Type> &operator=(Vector<Type> &&vec);

    iterator begin();
    iterator end();
    const const_iterator cbegin() const;
    const const_iterator cend() const;
    const const_iterator begin() const;
    const const_iterator end() const;

    Type &at(size_t index);
    const Type &at(size_t index) const;

    Type& operator[](size_t index);
    const Type &operator[](size_t index) const;

    void clean_vector() override;
    void push_back(const Type &elem);
    void erase(iterator &iter);
    size_t get_size() const override;

private:
    void alloca_vector(size_t size);
    const size_t START_SIZE = 10;
    void resize();
    Type *value;
    size_t cur_size;
};

template <typename Type>
Vector<Type>::Vector()
{
    alloca_vector(START_SIZE);
}

template <typename Type>
Vector<Type>::Vector(size_t size, const Type &data)
{
    alloca_vector(size);
    for (size_t i = 0; i < size; ++i)
        push_back(data);
}

template <typename Type>
void Vector<Type>::alloca_vector(size_t size)
{
    time_t t_time = time(NULL);
    value = new Type[size];
    if (!value)
        throw MemoryError(__FILE__,
                          typeid(*this).name(),
                          __LINE__,
                          ctime(&t_time));
    cur_size = size;
}


template<typename Type>
Vector<Type>::Vector(std::initializer_list<Type> arr)
{
    alloca_vector(arr.size());
    this->size = 0;
    value = nullptr;
    for (auto &element : arr)
    {
        this->push_back(element);
    }
}

template<typename Type>
Vector<Type>::Vector(const Vector<Type> &vector)
{
    this->value = vector.value;
    this->cur_size = vector.cur_size;
    this->size = vector.size;
}

template <typename Type>
Vector<Type>::Vector(Vector<Type> &&vec) noexcept
{
    value = vec.value;
    cur_size = vec.cur_size;
    this->size = vec.size;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(const Vector<Type> &vector)
{
    value = vector.value;
    this->size = vector.size;
    cur_size = vector.cur_size;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(Vector<Type> &&vector)
{
    value = vector.value;
    this->size = vector.size;
    cur_size = vector.cur_size;
    vector.~Vector();

    return *this;
}


template <typename Type>
typename Vector<Type>::iterator Vector<Type>::begin()
{
    return iterator(this, 0);
}

template <typename Type>
typename Vector<Type>::iterator Vector<Type>::end()
{
    return iterator(this, get_size());
}

template <typename Type>
const typename Vector<Type>::const_iterator Vector<Type>::cbegin() const
{
    return const_iterator(this, get_size());
}

template <typename Type>
const typename Vector<Type>::const_iterator Vector<Type>::cend() const
{
    return const_iterator(this, get_size());
}

template <typename Type>
const typename Vector<Type>::const_iterator Vector<Type>::begin() const
{
    return cbegin();
}

template <typename Type>
const typename Vector<Type>::const_iterator Vector<Type>::end() const
{
    return cend();
}

template <typename Type>
Type &Vector<Type>::at(size_t index)
{
    time_t time_ = time(NULL);
    if (index < 0 || index >= this->size)
    {
        throw IndexError(__FILE__,
                         typeid(*this).name(),
                         __LINE__,
                         ctime(&time_));
    }
    return value[index];
}

template <typename Type>
const Type &Vector<Type>::at(size_t index) const
{
    time_t time_ = time(NULL);
    if (index < 0 || index >= this->size)
    {
        throw IndexError(__FILE__,
                         typeid(*this).name(),
                         __LINE__,
                         ctime(&time_));
    }
    return value[index];
}


template <typename Type>
void Vector<Type>::clean_vector()
{
    if (!value)
        return;
    delete[] value;
    value = nullptr;
    this->size = 0;
    cur_size = 0;
}

template <typename Type>
void Vector<Type>::resize()
{
    size_t new_size = this->size * 2;
    Type *new_value = new Type[new_size];
    for (size_t i = 0; i < this->size; ++i)
        new_value[i] = value[i];

    delete[] value;
    value = new_value;
    cur_size = new_size;
}

template <typename Type>
void Vector<Type>::erase(iterator &iter)
{
    time_t time_ = time(NULL);
    if (iter > end())
    {
        throw IndexError(__FILE__,
                         typeid(*this).name(),
                         __LINE__,
                         ctime(&time_));
    }
    for (auto i = iter; i != end() - 1; ++i)
        *i = *(i + 1);
    this->size--;
}

template <typename Type>
size_t Vector<Type>::get_size() const
{
    return this->size;
}

template <typename Type>
void Vector<Type>::push_back(const Type &val)
{
    if (!value)
    {
        alloca_vector(START_SIZE);
    }
    if (this->size == cur_size)
        resize();
    value[this->size++] = val;
}

template <typename Type>
Type &Vector<Type>::operator[](size_t index)
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= this->size)
        throw IndexError(__FILE__,
                         typeid(*this).name(),
                         __LINE__,
                         ctime(&t_time));

    return value[index];
}

#endif
