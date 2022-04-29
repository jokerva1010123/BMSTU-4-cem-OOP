#ifndef MATRIX_BASE_HPP
#define MATRIX_BASE_HPP


#include "iterator_const.hpp"
#include "errors.hpp"
#include "iterator.hpp"

#include <cstddef>
#include <ctime>
#include <iostream>

template <class Type>
class BaseMatrix
{
    class ProxyElem
    {
    public:
        ProxyElem(size_t n, Type *elem);

        Type &operator[](size_t index);
        const Type &operator[](size_t index) const;

    private:
        size_t col;
        Type *data;
    };

public:
    typedef Iterator<Type> iterator;
    typedef ConstIterator<Type> const_iterator;

    explicit BaseMatrix(size_t n, size_t m);
    explicit BaseMatrix(size_t n, size_t m, const Type &arr);

    BaseMatrix(size_t, size_t, iterator, iterator);
    BaseMatrix(size_t, size_t, const_iterator, const_iterator);

    BaseMatrix(size_t n, size_t m, std::initializer_list<Type>);
    BaseMatrix(const BaseMatrix &arr);
    BaseMatrix(BaseMatrix &&arr);

    virtual ~BaseMatrix();

    BaseMatrix &operator=(std::initializer_list<Type>);
    BaseMatrix &operator=(const BaseMatrix &arr);
    BaseMatrix &operator=(BaseMatrix &&arr);

    ProxyElem operator[](size_t index);
    const ProxyElem operator[](size_t index) const;

    iterator begin();
    iterator end();
    const_iterator cbegin();
    const_iterator cend();

    iterator rbegin();
    iterator rend();
    const_iterator rcbegin();
    const_iterator rcend();

    size_t get_row();
    size_t get_columns();
    size_t get_cur_size();

    void swap(BaseMatrix &arr);
    void do_zero();

    template <class Type1>
    friend inline void swap(BaseMatrix<Type1> &, BaseMatrix<Type1> &);

    template <class Type1>
    friend inline bool operator==(const BaseMatrix<Type1> &, const BaseMatrix<Type1> &);
    template <class Type1>
    friend inline bool operator!=(const BaseMatrix<Type1> &, const BaseMatrix<Type1> &);
    template <class Type1>
    friend inline bool operator<(const BaseMatrix<Type1> &, const BaseMatrix<Type1> &);
    template <class Type1>
    friend inline bool operator<=(const BaseMatrix<Type1> &, const BaseMatrix<Type1> &);
    template <class Type1>
    friend inline bool operator>(const BaseMatrix<Type1> &, const BaseMatrix<Type1> &);
    template <class Type1>
    friend inline bool operator>=(const BaseMatrix<Type1> &, const BaseMatrix<Type1> &);


    template <class Type1>
    friend inline std::ostream &operator<<(std::ostream &, const BaseMatrix<Type1> &);

protected:
    size_t row;
    size_t col;
    size_t cur_size;
    Type *data;
};


template <class Type>
BaseMatrix<Type>::ProxyElem::ProxyElem(size_t col, Type *data)
    : col(col), data(data) {}

template <class Type>
Type &BaseMatrix<Type>::ProxyElem::operator [](size_t index)
{
    if (index < this->col)
    {
        return *(this->data + index);
    }
    else
    {
        time_t time_ = time(NULL);
        throw IndexError(__FILE__,
                         typeid(*this).name(),
                         __LINE__,
                         ctime(&time_));
    }
}

template <class Type>
const Type &BaseMatrix<Type>::ProxyElem::operator [](size_t index) const
{
    if (index < this->count_column)
    {
        return *(this->data + index);
    }
    else
    {
        time_t time_ = time(NULL);
        throw IndexError(__FILE__,
                         typeid(*this).name(),
                         __LINE__,
                         ctime(&time_));
    }
}

template <class Type>
BaseMatrix<Type>::BaseMatrix(size_t row, size_t col)
    : row(row), col(col), cur_size(row * col)
{
    try
    {
        this->data = new Type[this->cur_size];
    }
    catch (std::bad_alloc &ex)
    {
        time_t time_ = time(NULL);
        throw IndexError(__FILE__,
                         typeid(*this).name(),
                         __LINE__,
                         ctime(&time_));
    }
}

template <class Type>
BaseMatrix<Type>::BaseMatrix(size_t row, size_t col, const Type &arr)
    : BaseMatrix(row, col)
{
    for (size_t i = 0; i < this->cur_size; ++i)
    {
        this->data[i] = arr;
    }
}

template <class T>
BaseMatrix<T>::BaseMatrix(size_t row_count, size_t col_count, iterator first, iterator last)
    : BaseMatrix(row_count, col_count)
{
    size_t size = this->cur_size <= static_cast<size_t>(last - first) ? this->cur_size : static_cast<size_t>(last - first);

    for (size_t i = 0; i < size; ++i, ++first)
    {
        this->data[i]  = *first;
    }
    for (size_t i = size; i < this->cur_size; ++i)
    {
        this->data[i] = 0;
    }
}

template <class T>
BaseMatrix<T>::BaseMatrix(size_t row_count, size_t col_count, const_iterator first, const_iterator last)
    : BaseMatrix(row_count, col_count)
{
    size_t size = this->cur_size <= static_cast<size_t>(last - first) ? this->cur_size : static_cast<size_t>(last - first);
    for (size_t i = 0; i < size; ++i, ++first)
    {
        this->data[i] = *first;
    }
    for (size_t i = size; i < this->cur_size; ++i)
    {
        this->data[i] = 0;
    }
}

template <class Type>
BaseMatrix<Type>::BaseMatrix(size_t row, size_t col,
                             std::initializer_list<Type> arr)
    : BaseMatrix(row, col)
{
    typename std::initializer_list<Type>::iterator iter_arr = arr.begin();
    size_t size;
    if (this->cur_size <= arr.size())
    {
        size = this->cur_size;
    }
    else
    {
        size = arr.size();
    }

    for (size_t i = 0; i < this->cur_size; ++i, ++iter_arr)
    {
        this->data[i] = *iter_arr;
    }
}

template <class Type>
BaseMatrix<Type>::BaseMatrix(const BaseMatrix &arr)
    : BaseMatrix(arr.row, arr.col)
{
    std::copy(arr.data, arr.data + arr.cur_size, this->data);
}

template <class Type>
BaseMatrix<Type>::BaseMatrix(BaseMatrix &&arr)
    : row(arr.row), col(arr.col), data(arr.data)
{
    arr.row = 0;
    arr.col = 0;
    arr.cur_size = 0;
    arr.data = nullptr;
}

template <class Type>
BaseMatrix<Type>::~BaseMatrix()
{
    this->row = 0;
    this->col = 0;
    this->cur_size = 0;
    delete data; // delete[]
    this->data = nullptr;
}

template <class Type>
BaseMatrix<Type> &BaseMatrix<Type>::operator=(std::initializer_list<Type> arr)
{
    typename std::initializer_list<Type>::iterator iter_arr = arr.begin();
    size_t size;
    if (this->cur_size <= arr.size())
    {
        size = this->cur_size;
    }
    else
    {
        size = arr.size();
    }

    for (size_t i = 0; i < size; ++i, ++iter_arr)
    {
        this->data[i] = *iter_arr;
    }

    for (size_t i = 0; i < this->cur_size; ++i)
    {
        this->data[i] = 0;
    }

    return *this;
}


template <class Type>
BaseMatrix<Type> &BaseMatrix<Type>::operator=(const BaseMatrix &arr)
{
    if (arr != this)
    {
        this->row = arr.row;
        this->col = arr.col;
        this->cur_size = arr.cur_size;

        try
        {
            delete[] this->data;
            this->data = new Type[this->cur_size];
        }
        catch (std::bad_alloc)
        {
            time_t time_ = time(NULL);
            throw MemoryError(__FILE__,
                              typeid(*this).name(),
                              __LINE__,
                              ctime(&time_));
        }

        std::copy(arr.data, arr.data + arr.cur_size, this->data);
    }

    return *this;
}


template <class Type>
BaseMatrix<Type> &BaseMatrix<Type>::operator=(BaseMatrix &&arr)
{
    if (arr != this)
    {
        this->row = arr.row;
        this->col = arr.col;
        this->cur_size = arr.cur_size;
        delete[] this->data;
        this->data = new Type[this->cur_size];

        arr.row = 0;
        arr.col = 0;
        arr.cur_size = 0;
        arr.data = nullptr;
    }

    return *this;
}

template <class Type>
typename BaseMatrix<Type>::ProxyElem BaseMatrix<Type>::operator[](size_t index)
{
    if (index < this->row)
    {
        return ProxyElem(this->col, this->data + this->col * index);
    }
    else
    {
        time_t time_ = time(NULL);
        throw IndexError(__FILE__,
                         typeid(*this).name(),
                         __LINE__,
                         ctime(&time_));
    }
}

template <class Type>
const typename BaseMatrix<Type>::ProxyElem BaseMatrix<Type>::operator[](size_t index) const
{
    if (index < this->row)
    {
        return ProxyElem(this->col, this->data + this->col * index);
    }
    else
    {
        time_t time_ = time(NULL);
        throw IndexError(__FILE__,
                         typeid(*this).name(),
                         __LINE__,
                         ctime(&time_));
    }
}


template <class Type>
typename BaseMatrix<Type>::iterator BaseMatrix<Type>::begin()
{
    return iterator(this->data);
}


template <class Type>
typename BaseMatrix<Type>::iterator BaseMatrix<Type>::end()
{
    return iterator(this->data + this->cur_size);
}

template <class Type>
typename BaseMatrix<Type>::const_iterator BaseMatrix<Type>::cbegin()
{
    return const_iterator(this->data);
}

template <class Type>
typename BaseMatrix<Type>::const_iterator BaseMatrix<Type>::cend()
{
    return const_iterator(this->data + this->cur_size);
}

template <class Type>
typename BaseMatrix<Type>::iterator BaseMatrix<Type>::rbegin()
{
    return iterator(this->data + this->cur_size - 1);
}

template <class Type>
typename BaseMatrix<Type>::iterator BaseMatrix<Type>::rend()
{
    return iterator(this->data - 1);
}

template <class Type>
typename BaseMatrix<Type>::const_iterator BaseMatrix<Type>::rcbegin()
{
    return const_iterator(this->data + this->cur_size - 1);
}

template <class Type>
typename BaseMatrix<Type>::const_iterator BaseMatrix<Type>::rcend()
{
    return const_iterator(this->data - 1);
}


template <class Type>
size_t BaseMatrix<Type>::get_row()
{
    return this-> row;
}

template <class Type>
size_t BaseMatrix<Type>::get_columns()
{
    return this->col;
}

template <class Type>
size_t BaseMatrix<Type>::get_cur_size()
{
    return this->cur_size;
}

template <class Type>
void BaseMatrix<Type>::swap(BaseMatrix<Type> &arr)
{
    std::swap(this->row, arr.row);
    std::swap(this->col, arr.col);
    std::swap(this->cur_size, arr.cur_size);
    std::swap(this->data, arr.data);
}

template <class Type>
void BaseMatrix<Type>::do_zero()
{
    for (size_t i = 0; i < this->cur_size; ++i)
    {
        this->data[i] = Type();
    }
}




template <class T>
void swap(BaseMatrix<T> &lhs, BaseMatrix<T> &rhs)
{
    lhs.swap(rhs);
}

template <class T>
bool operator==(const BaseMatrix<T> &lhs, const BaseMatrix<T> &rhs)
{
    bool are_equal = lhs.size() == rhs.size();

    if (are_equal)
    {
        for (size_t i = 0; i < lhs.size() && are_equal; ++i)
        {
            if (lhs[i] != rhs[i])
            {
                are_equal = false;
            }
        }
    }

    return are_equal;
}

template <class T>
bool operator!=(const BaseMatrix<T> &lhs, const BaseMatrix<T> &rhs)
{
    return !(rhs == lhs);
}

template <class T>
bool operator<(const BaseMatrix<T> &lhs, const BaseMatrix<T> &rhs)
{
    bool is_less = lhs.size() < rhs.size();

    if (!is_less && lhs.size() == rhs.size())
    {
        for (size_t i = 0; i < lhs.size() && !is_less; ++i)
        {
            if (lhs[i] < rhs[i])
            {
                is_less = true;
            }
        }
    }

    return is_less;
}

template <class T>
bool operator<=(const BaseMatrix<T> &lhs, const BaseMatrix<T> &rhs)
{
    return lhs < rhs || lhs == rhs;
}

template <class T>
bool operator>(const BaseMatrix<T> &lhs, const BaseMatrix<T> &rhs)
{
    return !(lhs < rhs) && !(lhs == rhs);
}

template <class T>
bool operator>=(const BaseMatrix<T> &lhs, const BaseMatrix<T> &rhs)
{
    return lhs > rhs || lhs == rhs;
}




template <class Type>
std::ostream &operator<<(std::ostream &stream, const BaseMatrix<Type> &mtx)
{
    for (size_t i = 0; i < mtx.row(); ++i)
    {
        for (size_t j = 0; j < mtx.col(); ++j)
        {
            stream << mtx[i][j] << " ";
        }

        stream << std::endl;
    }

    return stream;
}


#endif // MATRIX_BASE_HPP
