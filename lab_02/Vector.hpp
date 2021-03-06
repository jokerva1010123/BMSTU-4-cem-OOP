#ifndef class_Vector_hpp
#define class_Vector_hpp

#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <cmath>

#include "Vector.h"
#include "my_errors.h"

using namespace std;

template<typename Type>
Vector<Type>::Vector()
{
    num_elem = 0;
    new_dyn_mem(num_elem);
}

template<typename Type>
Vector<Type>::Vector(int num_elements)
{
    time_t t_time = time(NULL);
    if (num_elements < 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    num_elem = num_elements;
    new_dyn_mem(num_elem);

    if (!data_list)
        throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Iterator<Type> iter(*this);
    for (; iter; iter++)
        *iter = 0;
}

template<typename Type>
Vector<Type>::Vector(int num_elements, Type* vec)
{
    time_t t_time = time(NULL);
    if (num_elements <= 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    num_elem = num_elements;
    new_dyn_mem(num_elem);

    Iterator<Type> iter(*this);
    for (int i = 0; iter; i++, iter++)
        *iter = vec[i];
}

template<typename Type>
Vector<Type>::Vector(int num_elements, Type vec, ...)
{
    time_t t_time = time(NULL);
    if (num_elements < 1)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    num_elem = num_elements;
    new_dyn_mem(num_elem);

    if (!data_list)
        throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Iterator<Type> iter(*this);
    va_list ap;
    va_start(ap, vec);
    for (; iter; iter++)
    {
        *iter = vec;
        vec = va_arg(ap, Type);
    }
    va_end(ap);
}

template<typename Type>
Vector<Type>::Vector(std::initializer_list<Type> args)
{
    if (args.size() == 0)
        Vector();

    num_elem = int(args.size());
    new_dyn_mem(num_elem);

    Iterator<Type> iter(*this);
    for (auto &element : args)
    {
        *iter = element;
        iter++;
    }
}

template<typename Type>
Vector<Type>::Vector(const Vector<Type> &vec)
{
    num_elem = vec.num_elem;
    new_dyn_mem(num_elem);

    Iterator<Type> iter_new(*this);
    Iterator<Type> iter(vec);
    for (; iter_new; iter++, iter_new++)
        *iter_new = *iter;
}

template<typename Type>
Vector<Type>::~Vector<Type>()
{
    if (data_list)
        data_list.reset();
}

template<typename Type>
Vector<Type>& Vector<Type>::operator =(const Vector<Type>& vec)
{
    num_elem = vec.num_elem;
    new_dyn_mem(num_elem);

    Iterator<Type> iter_new(*this);
    Iterator<Type> iter(vec);
    for (; iter_new; iter_new++, iter++)
        *iter_new = *iter;

    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator =(Vector<Type> &&vec) noexcept
{
    num_elem = vec.num_elem;
    new_dyn_mem(num_elem);
    data_list = vec.data_list;
    vec.data_list.reset();

    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator =(std::initializer_list<Type> args)
{
    num_elem = int(args.size());
    new_dyn_mem(num_elem);

    Iterator<Type> iter(*this);
    for (auto &element : args)
    {
        *iter = element;
        iter++;
    }

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator +(const Vector<Type>& vec) const
{
    time_t t_time = time(NULL);
    if (num_elem < 0 || vec.num_elem < 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    int max_len = max(num_elem, vec.num_elem);
    Vector<Type> new_vector(max_len);
    sum_vectors(new_vector, *this, vec);

    return new_vector;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator +=(const Vector<Type>& vec)
{
    time_t t_time = time(NULL);
    if (num_elem < 0 || vec.num_elem < 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    sum_vectors(*this, *this, vec);

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::sum(const Vector<Type> &vector) const
{
    return operator+(vector);
}

template <typename Type>
Vector<Type>& Vector<Type>::sumEqual(const Vector<Type> &vector)
{
    return operator+=(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::operator -(const Vector<Type>& vec) const
{
    time_t t_time = time(NULL);
    if (num_elem < 0 || vec.num_elem < 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    int max_len = max(num_elem, vec.num_elem);
    Vector<Type> new_vector(max_len);
    difference_vectors(new_vector, *this, vec);

    return new_vector;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator -=(const Vector<Type>& vec)
{
    time_t t_time = time(NULL);
    if (num_elem < 0 || vec.num_elem < 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    difference_vectors(*this, *this, vec);

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::sub(const Vector<Type> &vector) const
{
    return operator -(vector);
}

template<typename Type>
Vector<Type>& Vector<Type>::subEqual(const Vector<Type> &vector)
{
    return operator -=(vector);
}

template<typename Type>
Vector<Type> Vector<Type>::operator *(const Type& mult) const
{
    time_t t_time = time(NULL);
    if (num_elem <= 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    Vector<Type> new_vector(*this);
    Iterator<Type> iter(new_vector);
    for (; iter; iter++)
        *iter *= mult;

    return new_vector;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator *=(const Type& mult)
{
    time_t t_time = time(NULL);
    if (num_elem <= 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Iterator<Type> iter(*this);
    for (; iter; iter++)
        *iter *= mult;

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::mulNum(const Type& mult) const
{
    return operator *(mult);
}

template<typename Type>
Vector<Type>& Vector<Type>::mulNumEqual(const Type& mult)
{
    return operator *=(mult);
}

template<typename Type>
Vector<Type> Vector<Type>::operator /(const Type &div) const
{
    time_t t_time = time(NULL);
    if (!div)
        throw zero_divError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Type div_new = 1 / div;
    Vector<Type>new_vector(*this);
    new_vector *= div_new;

    return new_vector;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator /=(const Type& div)
{
    time_t t_time = time(NULL);
    if (!div)
        throw zero_divError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Type div_new = 1 / div;
    *this *= div_new;

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::divNum(const Type& div) const
{
    return operator /(div);
}

template<typename Type>
Vector<Type>& Vector<Type>::divNumEqual(const Type& div)
{
    return operator /=(div);
}

template<typename Type>
Vector<Type>& Vector<Type>::operator &=(const Vector<Type>& vec)
{
    if (num_elem != 3)
        return *(new Vector<Type>);

    double x = data_list.get()[1] * vec.data_list.get()[2] - data_list.get()[2] * vec.data_list.get()[1];
    double y = data_list.get()[2] * vec.data_list.get()[0] - data_list.get()[0] * vec.data_list.get()[2];
    double z = data_list.get()[0] * vec.data_list.get()[1] - data_list.get()[1] * vec.data_list.get()[0];

    *this = Vector<Type>(3, x, y, z);
    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator &(const Vector<Type>& vec)
{
    time_t t_time = time(NULL);
    if (num_elem != 3)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    double x = data_list.get()[1] * vec.data_list.get()[2] - data_list.get()[2] * vec.data_list.get()[1];
    double y = data_list.get()[2] * vec.data_list.get()[0] - data_list.get()[0] * vec.data_list.get()[2];
    double z = data_list.get()[0] * vec.data_list.get()[1] - data_list.get()[1] * vec.data_list.get()[0];
    Vector<Type> new_vector(3, x, y, z);
    return new_vector;
}

template<typename Type>
Vector<Type> Vector<Type>::vectorMul(const Vector<Type>& vec)
{
    return operator &(vec);
}

template<typename Type>
Vector<Type>& Vector<Type>::vectorMulEqual(const Vector<Type>& vec)
{
    return operator &=(vec);
}

template <typename Type>
Type Vector<Type>::operator *(const Vector<Type>& vec) const
{
    time_t t_time = time(NULL);
    if (num_elem < 0 || vec.num_elem < 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    int max_len = max(num_elem, vec.num_elem);
    Vector<Type> new_vector(max_len);
    mult_vectors(new_vector, *this, vec);

    return new_vector.sum_all_elem();
}

template <typename Type>
Type Vector<Type>::operator *=(const Vector<Type>& vec)
{
    time_t t_time = time(NULL);
    if (num_elem < 0 || vec.num_elem < 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    mult_vectors(*this, *this, vec);

    return (*this).sum_all_elem();
}

template <typename Type>
Type Vector<Type>::scalarMul(const Vector<Type>& vec) const
{
    return operator *(vec);
}

template<typename Type>
Vector <Type> Vector <Type>::operator ^(const Vector<Type> & vec) const
{
    time_t t_time = time(NULL);
    if (num_elem < 0 || vec.num_elem < 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    int max_len = max(num_elem, vec.num_elem);
    Vector<Type> new_vector(max_len);
    mult_vectors(new_vector, *this, vec);
    return new_vector;
}

template<typename Type>
Vector<Type>& Vector <Type>::operator ^=(const Vector<Type> & vec)
{
    time_t t_time = time(NULL);
    if (num_elem < 0 || vec.num_elem < 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    mult_vectors(*this, *this, vec);
    return *this;
}

template<typename Type>
Vector <Type> Vector <Type>::mulElement(const Vector<Type> & vec) const
{
    return operator ^(vec);
}

template<typename Type>
Vector<Type>& Vector <Type>::mulElementEqual(const Vector<Type> & vec)
{
    return operator ^=(vec);
}

template <typename Type>
Vector<Type> Vector<Type>::operator -()
{
    Vector<Type> new_vector(*this);
    Iterator<Type> iter(new_vector);
    for (; iter; iter++)
        *iter = -*iter;

    return new_vector;
}

template <typename Type>
Vector<Type> Vector<Type>::neg()
{
    return operator -();
}

template <typename Type>
bool Vector<Type>::operator ==(const Vector<Type>& vec) const
{
    int equal = 1;
    if (num_elem != vec.num_elem)
        return false;
    else
    {
        Iterator<Type> iter1(*this);
        Iterator<Type> iter2(vec);

        for (; iter1 && equal; iter1++, iter2++)
            if (fabs(*iter1 - *iter2) > EPS)
                equal = 0;
    }
    return equal;
}

template <typename Type>
bool Vector<Type>::operator !=(const Vector<Type>& vec) const
{
    if (*this == vec)
        return false;
    else
        return true;
}

template <typename Type>
bool Vector<Type>::isEqual(const Vector<Type>& vec) const
{
    return operator ==(vec);
}

template <typename Type>
bool Vector<Type>::isNotEqual(const Vector<Type>& vec) const
{
    return operator !=(vec);
}

template<typename Type>
Type& Vector<Type>::operator [](int index)
{
    return get_elem_Vector(index);
}

template<typename Type>
const Type& Vector<Type>::operator [](int index) const
{
    return get_elem_Vector(index);
}

template<typename Type>
Type& Vector<Type>::get_elem_Vector(int index)
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= num_elem)
        throw indexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Iterator<Type> iter(*this);
    for (int i = 0; i < index; i++, iter++)
        ;

    return *iter;
}

template<typename Type>
const Type& Vector<Type>::get_elem_Vector(int index) const
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= num_elem)
        throw indexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Iterator<Type> iter(*this);
    for (int i = 0; i < index; i++, iter++)
        ;

    return *iter;
}

template<typename Type>
bool Vector<Type>::set_elem_Vector(int index, const Type& num)
{
    if (index < 0 || index >= num_elem)
        return false;

    get_elem_Vector(index) = num;
    return true;
}

template<typename Type>
bool Vector<Type>::is_single() const
{
    if (abs(this->len() - 1) < EPS)
        return true;
    else
        return false;
}

template<typename Type>
bool Vector<Type>::is_zero() const
{
    if (this->len() == 0)
        return true;
    else
        return false;
}

template<typename Type>
int Vector<Type>::size() const
{
    return num_elem;
}

template<typename Type>
Type Vector<Type>::len(void) const
{
    time_t t_time = time(NULL);
    if (num_elem < 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Iterator<Type> iter(*this);
    double sum = 0;
    for (; iter; iter++)
        sum += *iter * *iter;

    return sqrt(sum);
}

template<typename Type>
Vector<Type> Vector<Type>::get_single_vector() const
{
    Vector<Type> new_vector(*this);
    Type len = this->len();

    Iterator<Type> iter(new_vector);
    for (; iter; iter++)
        *iter /= len;

    return new_vector;
}

template<typename Type>
double Vector<Type>::angle_between_vectors(const Vector<Type> &vec) const
{
    time_t t_time = time(NULL);
    if (!this->len() || !vec.len())
        throw zero_divError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    double angle = (*this * vec)/(this->len() * vec.len());
    return acos(angle) * 180 / M_PI;
}

template<typename Type>
bool Vector<Type>::is_collinearity(const Vector<Type>& vec) const
{
    if (this->angle_between_vectors(vec) < EPS)
        return true;
    else
        return false;
}

template<typename Type>
bool Vector<Type>::is_orthogonality(const Vector<Type>& vec) const
{
    if (abs(this->angle_between_vectors(vec) - 90) < EPS)
        return true;
    else
        return false;
}

template<typename Type>
Iterator<Type> Vector<Type>::begin() noexcept
{
    Iterator<Type> iterator(*this);
    return iterator;
}

template<typename Type>
Iterator<Type> Vector<Type>::end() noexcept
{
    Iterator<Type> iterator(*this);
    return iterator + size;
}

template<typename Type>
Iterator<Type> Vector<Type>::begin() const noexcept
{
    Iterator<Type> constIterator(*this);
    return constIterator;
}

template<typename Type>
Iterator<Type> Vector<Type>::end() const noexcept
{
    Iterator<Type> constIterator(*this);
    return constIterator + this->num_elem;
}

template<typename Type>
Iterator<Type> Vector<Type>::constBegin() const noexcept
{
    Iterator<Type> constIterator(*this);
    return constIterator;
}

template<typename Type>
Iterator<Type> Vector<Type>::constEnd() const noexcept
{
    Iterator<Type> constIterator(*this);
    return constIterator + this->num_elem;
}

template<typename Type>
Type Vector<Type>::sum_all_elem()
{
    time_t t_time = time(NULL);
    if (num_elem <= 0)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Iterator<Type> iter(*this);
    Type sum = 0;
    for (; iter; iter++)
        sum += *iter;

    return sum;
}

template <typename Type>
void Vector<Type>::sum_vectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const
{
    Iterator<Type> iter_result(result);
    Iterator<Type> iter_vec1(vec1);
    Iterator<Type> iter_vec2(vec2);
    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= vec1.num_elem)
            *iter_result = *iter_vec2;
        else if (i >= vec2.num_elem)
            *iter_result = *iter_vec1;
        else
            *iter_result = *iter_vec1 + *iter_vec2;
    }
}

template <typename Type>
void Vector<Type>::difference_vectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const
{
    Iterator<Type> iter_result(result);
    Iterator<Type> iter_vec1(vec1);
    Iterator<Type> iter_vec2(vec2);
    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= vec1.num_elem)
            *iter_result = -*iter_vec2;
        else if (i >= vec2.num_elem)
            *iter_result = *iter_vec1;
        else
            *iter_result = *iter_vec1 - *iter_vec2;
    }
}

template <typename Type>
void Vector<Type>::mult_vectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const
{
    Iterator<Type> iter_result(result);
    Iterator<Type> iter_vec1(vec1);
    Iterator<Type> iter_vec2(vec2);
    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= vec1.num_elem || i >= vec2.num_elem)
            *iter_result = 0;
        else
            *iter_result = *iter_vec1 * *iter_vec2;
    }
}

template <typename Type>
void Vector<Type>::new_dyn_mem(int num_elements)
{
    data_list.reset();
    std::shared_ptr<Type[]> sp_temp(new Type[num_elements], std::default_delete<Type[]>());
    data_list = sp_temp;
}

#endif /* class_Vector_hpp */
