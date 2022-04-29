#ifndef MATRIX_H
#define MATRIX_H


#include "matrix_base.hpp"

template <class Type>
class Matrix: public BaseMatrix<Type>
{
public:
    typedef typename BaseMatrix<Type>::iterator iterator;
    typedef typename BaseMatrix<Type>::const_iterator const_iterator;

    explicit Matrix(size_t n, size_t m);
    explicit Matrix(size_t n, size_t m, const Type &);

    Matrix(size_t, size_t, iterator, iterator);
    Matrix(size_t, size_t, const_iterator, const_iterator);

    Matrix(size_t n, size_t m, std::initializer_list<Type> arr);
    Matrix(const Matrix &arr);
    Matrix(Matrix &&arr);

    virtual ~Matrix() = default;

    Matrix &operator=(const Matrix &arr);
    Matrix &operator=(Matrix &&arr);
    Matrix &operator=(std::initializer_list<Type> arr);


    template <class Type1>
    friend Matrix<Type1> operator+(const Matrix<Type1> &, const Matrix<Type1> &);
    template <class Type1>
    friend Matrix<Type1> operator+(const Matrix<Type1> &, const Type1 &);
    Matrix &operator+=(const Matrix &);
    Matrix &operator+=(const Type &);
    template <class Type1>
    friend Matrix<Type1> operator-(const Matrix<Type1> &, const Matrix<Type1> &);
    template <class Type1>
    friend Matrix<Type1> operator-(const Matrix<Type1> &, const Type1 &);
    Matrix &operator-=(const Matrix &);
    Matrix &operator-=(const Type &);
    template <class Type1>
    friend Matrix<Type1> operator*(const Matrix<Type1> &, const Matrix<Type1> &);
    template <class Type1>
    friend Matrix<Type1> operator*(const Matrix<Type1> &, const Type1 &);
    Matrix &operator*=(const Matrix &);
    Matrix &operator*=(const Type &);
    template <class Type1>
    friend Matrix<Type1> operator/(const Matrix<Type1> &, const Type1 &);
    Matrix &operator/=(const Type &);
};



template <class Type>
Matrix<Type>::Matrix(size_t row, size_t col)
    : BaseMatrix<Type>(row, col) { }

template <class Type>
Matrix<Type>::Matrix(size_t row, size_t col, const Type &arr)
    : BaseMatrix<Type>(row, col, arr) { }

template <class Type>
Matrix<Type>::Matrix(size_t row, size_t col, std::initializer_list<Type> arr)
    : BaseMatrix<Type>(row, col, arr) { }

template <class Type>
Matrix<Type>::Matrix(const Matrix &arr)
    : BaseMatrix<Type>(arr) {}

template <class Type>
Matrix<Type>::Matrix(Matrix &&arr)
    : BaseMatrix<Type>(std::move(arr)) { }

template <class Type>
Matrix<Type> &Matrix<Type>::operator=(const Matrix<Type> &arr)
{
    BaseMatrix<Type>::operator=(arr);
    return *this;
}

template <class Type>
Matrix<Type> &Matrix<Type>::operator=(Matrix<Type> &&arr)
{
    BaseMatrix<Type>::operator=(std::move(arr));
    return *this;
}

template <class Type>
Matrix<Type>::Matrix(size_t row_count, size_t col_count, iterator first, iterator last)
    : BaseMatrix<Type>(row_count, col_count, first, last)
{
    printf("matrix");
}

template <class Type>
Matrix<Type>::Matrix(size_t row_count, size_t col_count, const_iterator first, const_iterator last)
    : BaseMatrix<Type>(row_count, col_count, first, last)
{
}

template <class Type>
Matrix<Type> &Matrix<Type>::operator=(std::initializer_list<Type> arr)
{
    BaseMatrix<Type>::operator=(arr);
    return *this;
}


template <class Type>
Matrix<Type> operator+(const Matrix<Type> &lhs, const Matrix<Type> &rhs)
{
    printf("matrix");
    Matrix<Type> result = lhs;
    size_t rows_count = lhs.get_row() < rhs.get_row() ? lhs.get_row() : rhs.get_row();
    size_t cols_count = lhs.get_columns() < rhs.get_columns() ? lhs.get_columns() : rhs.get_columns();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            result[i][j] += rhs[i][j];
        }
    }

    return result;
}

template <class Type>
Matrix<Type> operator+(const Matrix<Type> &mtx, const Type &value)
{
    printf("matrix");
    Matrix<Type> result = mtx;

    for (size_t i = 0; i < mtx.get_cur_size(); ++i)
    {
        result.data[i] += value;
    }

    return result;
}

template <class Type>
Matrix<Type> &Matrix<Type>::operator+=(const Matrix<Type> &rhs)
{
    printf("matrix");
    size_t rows_count = this->get_row() < rhs.get_row() ? this->get_row() : rhs.get_row();
    size_t cols_count = this->get_columns() < rhs.get_columns() ? this->get_columns() : rhs.get_columns();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            (*this)[i][j] += rhs[i][j];
        }
    }

    return *this;
}

template <class Type>
Matrix<Type> &Matrix<Type>::operator+=(const Type &value)
{
    printf("matrix");
    for (size_t i = 0; i < this->get_cur_size(); ++i)
    {
        this->data[i] += value;
    }

    return *this;
}

template <class Type>
Matrix<Type> operator-(const Matrix<Type> &lhs, const Matrix<Type> &rhs)
{
    printf("matrix");
    Matrix<Type> result = lhs;
    size_t rows_count = lhs.get_row() < rhs.get_row() ? lhs.get_row() : rhs.get_row();
    size_t cols_count = lhs.get_columns() < rhs.get_columns() ? lhs.get_columns() : rhs.get_columns();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            result[i][j] -= rhs[i][j];
        }
    }

    return result;
}

template <class Type>
Matrix<Type> operator-(const Matrix<Type> &mtx, const Type &value)
{
    printf("matrix");
    Matrix<Type> result = mtx;

    for (size_t i = 0; i < mtx.get_cur_size(); ++i)
    {
        result.data[i] -= value;
    }

    return result;
}

template <class Type>
Matrix<Type> &Matrix<Type>::operator-=(const Matrix<Type> &rhs)
{
    printf("matrix");
    size_t rows_count = this->get_row() < rhs.get_row() ? this->get_row() : rhs.get_row();
    size_t cols_count = this->get_columns() < rhs.get_columns() ? this->get_columns() : rhs.get_columns();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            (*this)[i][j] -= rhs[i][j];
        }
    }

    return *this;
}

template <class Type>
Matrix<Type> &Matrix<Type>::operator-=(const Type &value)
{
    printf("matrix");
    for (size_t i = 0; i < this->get_cur_size(); ++i)
    {
        this->data[i] -= value;
    }

    return *this;
}

template <class Type>
Matrix<Type> operator*(const Matrix<Type> &lhs, const Matrix<Type> &rhs)
{
    printf("matrix");
    if (lhs.get_columns() == rhs.get_row())
    {
        Matrix<Type> result = lhs;

        for (size_t i = 0; i < lhs.get_row(); ++i)
        {
            for (size_t j = 0; j < rhs.get_columns(); ++j)
            {
                for (size_t k = 0; k < lhs.get_columns(); ++k)
                {
                    result[i][j] += lhs[i][k] * rhs[k][j];
                }
            }
        }

        return result;
    }
    else
    {
        time_t t_time(NULL);
        throw IndexError(__FILE__,
                         "Matrix<Type>::operator*",
                         __LINE__,
                         ctime(&t_time));
    }
}

template <class Type>
Matrix<Type> &operator*(const Matrix<Type> &mtx, const Type &value)
{
    printf("matrix");
    Matrix<Type> result = mtx;

    for (size_t i = 0; i < mtx.get_cur_size(); ++i)
    {
        result.data[i] *= value;
    }

    return result;
}

template <class Type>
Matrix<Type> &Matrix<Type>::operator*=(const Matrix<Type> &rhs)
{
    printf("matrix");
    if (this->columns() == rhs.get_row())
    {
        for (size_t i = 0; i < this->get_row(); ++i)
        {
            for (size_t j = 0; j < rhs.get_columns(); ++j)
            {
                for (size_t k = 0; k < this->get_columns(); ++k)
                {
                    (*this)[i][j] = (*this)[i][k] * rhs[k][j];
                }
            }
        }

        return *this;
    }
    else
    {
        time_t t_time(NULL);
        throw IndexError(__FILE__,
                         typeid((*this).name(),
                                __LINE__,
                                ctime(&t_time)));
    }
}

template <class Type>
Matrix<Type> &Matrix<Type>::operator*=(const Type &value)
{
    printf("matrix");
    for (size_t i = 0; i < this->get_cur_size(); ++i)
    {
        this->data[i] *= value;
    }

    return *this;
}

template <class Type>
Matrix<Type> &operator/(const Matrix<Type> &mtx, const Type &value)
{
    printf("matrix");
    Matrix<Type> result = mtx;

    for (size_t i = 0; i < mtx.get_cur_size(); ++i)
    {
        result.data[i] /= value;
    }

    return result;
}

template <class Type>
Matrix<Type> &Matrix<Type>::operator/=(const Type &value)
{
    printf("matrix");
    for (size_t i = 0; i < this->get_cur_size(); ++i)
    {
        this->data[i] /= value;
    }

    return *this;
}


#endif // MATRIX_H
