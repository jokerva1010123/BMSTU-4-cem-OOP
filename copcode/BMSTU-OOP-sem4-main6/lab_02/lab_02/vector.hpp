#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "vector.h"
#include <limits>
#include <stdlib.h>
#include <stdarg.h>
#include <cstddef>
#include <cmath>
#include <math.h>
#include <exception>

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
    return iterator + this->count_elem;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::begin() const noexcept
{
    ConstIterator<Type> cIterator(*this);
    return cIterator;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::end() const noexcept
{
    ConstIterator<Type> cIterator(*this);
    return cIterator + this->count_elem;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::cBegin() const noexcept
{
    ConstIterator<Type> cIterator(*this);
    return cIterator;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::cEnd() const noexcept
{
    ConstIterator<Type> cIterator(*this);
    return cIterator + this->count_elem;
}

template<typename Type>
Vector<Type> Vector<Type>::vec_sum(const Vector<Type> &vector) const
{
    Vector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
    {
        *resultIterator = *resultIterator + *iterFrom;
    }

    return result;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::vec_sum(const Vector<Type1> &vector) const
{
    Vector<decltype(this->values[0] + vector.at(0))> result(*this);
    Iterator<decltype(this->values[0] + vector.at(0))> resultIterator = result.begin();
    ConstIterator<Type1> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
        *resultIterator = *resultIterator + *iterFrom;
    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::sum_el(const Type &elem) const
{
    Vector<Type> result(*this);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<Type> iterTo = result.begin();

    for (; iterFrom; iterFrom++, iterTo++)
    {
        *iterTo = *iterFrom + elem;
    }

    return result;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::sum_el(const Type1 &elem) const
{
    Vector<decltype(elem + this->values[0])> result(this->count_elem);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<decltype(elem + this->values[0])> iterTo = result.begin();

    for (; iterTo; iterFrom++, iterTo++)
    {
        *iterTo = *iterFrom + elem;
    }

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::vec_dif(const Vector<Type> &vector) const
{
    Vector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
    {
        *resultIterator = *resultIterator - *iterFrom;
    }

    return result;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::vec_dif(const Vector<Type1> &vector) const
{
    Vector<decltype(this->values[0] + vector.at(0))> result(*this);
    Iterator<decltype(this->values[0] + vector.at(0))> resultIterator = result.begin();
    ConstIterator<Type1> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
    {
        *resultIterator = *resultIterator - *iterFrom;
    }

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::dif_el(const Type &elem) const
{
    Vector<Type> result(*this);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<Type> iterTo = result.begin();

    for (; iterFrom; iterFrom++, iterTo++)
    {
        *iterTo = *iterFrom - elem;
    }

    return result;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::dif_el(const Type1 &elem) const
{
    Vector<decltype(elem + this->values[0])> result(this->count_elem);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<decltype(elem + this->values[0])> iterTo = result.begin();

    for (; iterTo; iterFrom++, iterTo++)
    {
        *iterTo = *iterFrom - elem;
    }

    return result;
}


template<typename Type>
Vector<Type> Vector<Type>::vec_mul(const Vector<Type> &vector) const
{
    Vector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
    {
        *resultIterator = *resultIterator * *iterFrom;
    }

    return result;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::vec_mul(const Vector<Type1> &vector) const
{
    Vector<decltype(this->values[0] + vector.at(0))> result(*this);
    Iterator<decltype(this->values[0] + vector.at(0))> resultIterator = result.begin();
    ConstIterator<Type1> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
    {
        *resultIterator = *resultIterator * *iterFrom;
    }

    return result;
}



template<typename Type>
Vector<Type> Vector<Type>:: mul_el(const Type &elem) const
{
    Vector<Type> result(*this);
    ConstIterator<Type> iterFrom = this->begin();
    Iterator<Type> iterTo = result.begin();

    for (; iterFrom; iterFrom++, iterTo++)
    {
        *iterTo = *iterFrom * elem;
    }

    return result;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>:: mul_el(const Type1 &elem) const
{
    Vector<decltype(elem + this->values[0])> result(this->count_elem);
    ConstIterator<Type> iterFrom = this->begin();
    Iterator<decltype(elem + this->values[0])> iterTo = result.begin();

    for (; iterTo; iterFrom++, iterTo++)
    {
        *iterTo = *iterFrom * elem;
    }

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::vec_div(const Vector<Type> &vector) const
{
    Vector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
    {
        *resultIterator = *resultIterator / *iterFrom;
    }

    return result;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::vec_div(const Vector<Type1> &vector) const
{
    Vector<decltype(this->values[0] + vector.at(0))> result(*this);
    Iterator<decltype(this->values[0] + vector.at(0))> resultIterator = result.begin();
    ConstIterator<Type1> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
    {
        *resultIterator = *resultIterator / *iterFrom;
    }

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::div_el(const Type &elem) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    if (!elem)
    {
        throw ZerodivError(__FILE__, typeid(*this).name(),
                           __LINE__, ctime(&cur_time));
    }

    Vector<Type> result(this->count_elem);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<Type> iterTo = result.begin();

    for (; iterFrom; iterFrom++, iterTo++)
    {
        *iterTo = *iterFrom / elem;
    }

    return result;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::div_el(const Type1 &elem) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    if (!elem)
    {
        throw ZerodivError(__FILE__, typeid(*this).name(),
                           __LINE__, ctime(&cur_time));
    }

    Vector<decltype(elem + this->values[0])> result(this->count_elem);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<decltype(elem + this->values[0])> iterTo = result.begin();

    for (; iterTo; iterFrom++, iterTo++)
    {
        *iterTo = *iterFrom / elem;
    }

    return result;
}

template<typename Type>
double Vector<Type>::angle(const Vector<Type> &vector) const
{
    time_t cur_time = time(NULL);
    if (!this->length<Type>() || !vector.length<Type>())
    {
        throw ZerodivError(__FILE__, typeid(*this).name(),
                           __LINE__, ctime(&cur_time));
    }

    double angle = (*this & vector) / (this->length<Type>() * vector.length<Type>());
    return acos(angle) * 180 / M_PI;
}

template<typename Type>
bool Vector<Type>::collinear_vectors(const Vector<Type> &vector) const
{
    if (this->angle(vector) < __FLT_EPSILON__)
    {
        return true;
    }

    return false;
}

template<typename Type>
bool Vector<Type>::orthgonal_vectors(const Vector<Type> &vector) const
{
    if (this->angle(vector) - 90 < __DBL_EPSILON__)
    {
        return true;
    }

    return false;
}

template<typename Type>
template<typename Type1>
Vector<Type1> Vector<Type>::get_unit() const
{
    Vector<Type1> unitVector(this->count_elem);
    Type len = this->length<Type>();

    Iterator<Type1> iteratorTo = unitVector.begin();
    ConstIterator<Type> iteratorFrom = this->begin();
    for (; iteratorFrom; iteratorFrom++, iteratorTo++)
    {
        *iteratorTo = *iteratorFrom / len;
    }

    return unitVector;
}

template<typename Type>
Vector<Type>::Vector()
{
    this->count_elem = 0;
    this->alloc_newvectormem(count_elem);
}

template<typename Type>
Vector<Type>::Vector(size_t size)
{
    time_t cur_time = time(NULL);

    this->alloc_newvectormem(size);
    if (!this->values)
    {
        throw MemoryError(__FILE__, typeid(*this).name(),
                          __LINE__, ctime(&cur_time));
    }

    this->count_elem = size;

    Iterator<Type> iterator = this->begin();
    for (; iterator; iterator++)
    {
         *iterator = 0;
    }
}

template<typename Type>
Vector<Type>::Vector(size_t size, Type elem, ...)
{
    time_t cur_time = time(NULL);
    if (size == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    this->alloc_newvectormem(size);
    if (!values)
    {
        throw MemoryError(__FILE__, typeid(*this).name(),
                          __LINE__, ctime(&cur_time));
    }

    this->count_elem = size;

    Iterator<Type> iterator(*this);
    va_list ap;
    va_start(ap, elem);
    for (; iterator; iterator++)
    {
        *iterator = elem;
        elem = va_arg(ap, Type);
    }
    va_end(ap);
}

template<typename Type>
Vector<Type>::Vector(size_t size, const Type *arrayFrom)
{
    if (size == 0)
    {
        time_t cur_time = time(NULL);
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    if (!arrayFrom)
    {
        time_t cur_time = time(NULL);
        throw CopyError(__FILE__, typeid(*this).name(),
                        __LINE__, ctime(&cur_time));
    }

    this->alloc_newvectormem(size);
    this->count_elem = size;

    Iterator<Type> iterator = this->begin();
    for (size_t i = 0; iterator; iterator++, i++)
    {
        *iterator = arrayFrom[i];
    }
}

template<typename Type>
Vector<Type>::Vector(std::initializer_list<Type> arguments)
{
    this->count_elem = arguments.size();
    this->alloc_newvectormem(count_elem);

    Iterator<Type> iterator = this->begin();
    for (auto &currentItem : arguments)
    {
        *iterator = currentItem;
        iterator++;
    }
}

template<typename Type>
Vector<Type>::Vector(Vector<Type> &&vector) noexcept: BaseVector(vector.count_elem)
{
    this->values = vector.values;
    vector.values = nullptr;
}

template<typename Type>
Vector<Type>::Vector(const Vector<Type> &vector): BaseVector(vector.count_elem)
{
    *this = vector;
}

template<typename Type>
template<typename Type_>
Vector<Type>::Vector(Type_ begin, Type_ end)
{
    Type_ copy_b = begin;
    int i = 0;
    for (auto iter = begin; end != iter; ++iter, ++i)
    { }

    this->count_elem = i;
    this->alloc_vector(i);

    i = 0;
    for (auto iter = copy_b; end != iter; ++iter, ++i)
    {
        this->val[i] = *iter;
    }
}

template<typename Type>
Type &Vector<Type>::at(size_t index)
{
    time_t cur_time = time(NULL);
    if (index >= count_elem)
    {
        throw IndexError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    Iterator<Type> iterator = this->begin();
    for (size_t i = 0; i < index; i++, iterator++)
    { }

    return *iterator;
}

template<typename Type>
const Type &Vector<Type>::at(size_t index) const
{
    if (index >= this->count_elem)
    {
        time_t cur_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    ConstIterator<Type> iterator = this->begin();
    for (size_t i = 0; i < index; i++, iterator++)
    { }

    return *iterator;
}

template<typename Type>
bool Vector<Type>::operator==(const Vector<Type> &vector) const
{
    bool equal = false;
    if (this->count_elem != vector.count_elem)
    {
        return equal;
    }

    equal = true;
    ConstIterator<Type> firstIterator = this->begin();
    for (ConstIterator<Type> secondIterator = vector.begin();
         firstIterator && equal;
         secondIterator++)
    {
        if (*firstIterator != *secondIterator)
        {
            equal = false;
        }
    }
    return equal;
}

template<>
bool Vector<float>::operator==(const Vector<float> &vector) const
{
    bool equal = false;
    if (this->count_elem != vector.count_elem)
    {
        return equal;
    }

    equal = true;
    ConstIterator<float> firstIterator = this->begin();
    for (ConstIterator<float> secondIterator = vector.begin();
         firstIterator && equal;
         secondIterator++)
    {
        if (std::abs(*firstIterator - *secondIterator) < std::numeric_limits<float>::epsilon())
        {
            equal = false;
        }
    }
    return equal;
}

template<>
bool Vector<double>::operator==(const Vector<double> &vector) const
{
    bool equal = false;
    if (this->count_elem != vector.count_elem)
    {
        return equal;
    }

    equal = true;
    ConstIterator<double> firstIterator = this->begin();
    for (ConstIterator<double> secondIterator = vector.begin();
         firstIterator && equal;
         secondIterator++)
    {
        if (std::abs(*firstIterator - *secondIterator) < std::numeric_limits<double>::epsilon())
        {
            equal = false;
        }
    }
    return equal;
}

template<typename Type>
bool Vector<Type>::is_equal(const Vector<Type> &vector) const
{
    return *this == vector;
}

template<typename Type>
bool Vector<Type>::operator!=(const Vector<Type> &vector) const
{
    bool not_equal = true;
    if (this->count_elem != vector.count_elem)
    {
        return not_equal;
    }

    not_equal = false;
    ConstIterator<Type> firstIterator = this->begin();
    for (ConstIterator<Type> secondIterator = vector.begin();
         firstIterator && !not_equal;
         secondIterator++)
    {
        if (*firstIterator != *secondIterator)
        {
            not_equal = true;
        }
    }

    return not_equal;
}

template<>
bool Vector<float>::operator!=(const Vector<float> &vector) const
{
    bool not_equal = true;
    if (this->count_elem != vector.count_elem)
    {
        return not_equal;
    }

    not_equal = false;
    ConstIterator<float> firstIterator = this->begin();
    for (ConstIterator<float> secondIterator = vector.begin();
         firstIterator && !not_equal;
         secondIterator++)
    {
        if (std::abs(*firstIterator - *secondIterator) < std::numeric_limits<float>::epsilon())
        {
            not_equal = true;
        }
    }

    return not_equal;
}

template<>
bool Vector<double>::operator!=(const Vector<double> &vector) const
{
    bool not_equal = true;
    if (this->count_elem != vector.count_elem)
    {
        return not_equal;
    }

    not_equal = false;
    ConstIterator<double> firstIterator = this->begin();
    for (ConstIterator<double> secondIterator = vector.begin();
         firstIterator && !not_equal;
         secondIterator++)
    {
        if (std::abs(*firstIterator - *secondIterator) < std::numeric_limits<double>::epsilon())
        {
            not_equal = true;
        }
    }
    return not_equal;
}

template<>
bool Vector<long double>::operator!=(const Vector<long double> &vector) const
{
    bool not_equal = true;
    if (this->count_elem != vector.count_elem)
    {
        return not_equal;
    }

    not_equal = false;
    ConstIterator<long double> firstIterator = this->begin();
    for (ConstIterator<long double> secondIterator = vector.begin();
         firstIterator && !not_equal;
         secondIterator++)
    {
        if (std::abs(*firstIterator - *secondIterator) < std::numeric_limits<long double>::epsilon())
        {
            not_equal = true;
        }
    }

    return not_equal;
}

template<typename Type>
bool Vector<Type>::is_not_equal(const Vector<Type> &vector) const
{
    return *this != vector;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator+=(const Vector<Type> &vector)
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0 || vector.count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    this->check_sizes(vector, __LINE__);

    *this = this->vec_sum(vector);

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator+=(const Type &elem)
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    *this = this->sum_el(elem);

    return *this;
}


template<typename Type>
void Vector<Type>::sum_eq(const Vector<Type> &vector)
{
    *this += vector;
}

template<typename Type>
void Vector<Type>::sum_eq(const Type &elem)
{
    *this += elem;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator-=(const Vector<Type> &vector)
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0 || vector.count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }
    this->check_sizes(vector, __LINE__);

    *this = this->vec_dif(vector);

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator-=(const Type &elem)
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    *this = this->dif_el(elem);

    return *this;
}

template<typename Type>
void Vector<Type>::dif_eq(const Vector<Type> &vector)
{
    *this -= vector;
}

template<typename Type>
void Vector<Type>::dif_eq(const Type &elem)
{
    *this -= elem;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator*=(const Vector<Type> &vector)
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }
    this->check_sizes(vector, __LINE__);

    *this = this->vec_mul(vector);
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator*=(const Type &elem)
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    *this = this->mul_el(elem);

    return *this;
}

template<typename Type>
void Vector<Type>::mul_eq(const Vector<Type> &vector)
{
    *this *= vector;
}

template<typename Type>
void Vector<Type>::mul_eq(const Type &elem)
{
    *this *= elem;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator/=(const Vector<Type> &vector)
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }
    this->check_sizes(vector, __LINE__);

    *this = this->vec_div(vector);
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator/=(const Type &elem)
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    *this = this->div_el(elem);

    return *this;
}

template<typename Type>
void Vector<Type>::div_eq(const Vector<Type> &vector)
{
    *this /= vector;
}

template<typename Type>
void Vector<Type>::div_eq(const Type &elem)
{
    *this /= elem;
}

template<typename Type>
Vector<Type> Vector<Type>::operator+(const Vector<Type> &vector) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0 || vector.count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }
    this->check_sizes(vector, __LINE__);

    return this->vec_sum(vector);
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator+(const Vector<Type1> &vector) const
{
    time_t currentTime = time(NULL);
    if (this->count_elem == 0)
        throw EmpryError(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));


    return this->vec_sum(vector);
}

template<typename Type>
Vector<Type> Vector<Type>::operator+(const Type &elem) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    return this->sum_el(elem);
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator+(const Type1 &elem) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    return this->sum_el(elem);
}

template<typename Type>
Vector<Type> Vector<Type>::operator-(const Vector<Type> &vector) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0 || vector.count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }
    this->check_sizes(vector, __LINE__);

    return this->vec_dif(vector);
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator-(const Vector<Type1> &vector) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    return this->vec_dif(vector);
}


template<typename Type>
Vector<Type> Vector<Type>::operator-(const Type &elem) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));

    return this->dif_el(elem);
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator-(const Type1 &elem) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));

    return this->dif_el(elem);
}


template<typename Type>
Vector<Type> Vector<Type>::operator*(const Vector<Type> &vector) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0 || vector.count_elem == 0)
    {
        EmpryError(__FILE__, typeid(*this).name(),
                   __LINE__, ctime(&cur_time));
    }
    this->check_sizes(vector, __LINE__);

    return this->vec_mul(vector);
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator*(const Vector<Type1> &vector) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        EmpryError(__FILE__, typeid(*this).name(),
                   __LINE__, ctime(&cur_time));
    }

    return this->vec_mul(vector);
}

template<typename Type>
Vector<Type> Vector<Type>::operator*(const Type &elem) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    return this->mul_el(elem);
}

template<typename Type>
template<typename Type1>
decltype(auto)Vector<Type>::operator*(const Type1 &elem) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    return this->mul_el(elem);
}


template<typename Type>
Vector<Type> Vector<Type>::vec_multip(const Vector<Type> &vector) const
{
    return *this * vector;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::vec_multip(const Vector<Type1> &vector) const
{
    return *this * vector;
}


template<typename Type>
Type Vector<Type>::operator&(const Vector<Type> &vector) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0 || vector.count_elem == 0)
    {
        EmpryError(__FILE__, typeid(*this).name(),
                   __LINE__, ctime(&cur_time));
    }

    this->check_sizes(vector, __LINE__);

    return this->vec_mul(vector).summary_value();
}

template<typename Type>
Type Vector<Type>::scalar_mult(const Vector<Type> &vector) const
{
    return this->vec_mul(vector).summary_value();
}

template<typename Type>
Vector<Type> Vector<Type>::operator^(const Vector<Type> &vector) const
{
    check_sizeforvecmul(vector, __LINE__);

    Type xCoord = -this->values[1] * vector.values[2] + this->values[2] * vector.values[1];
    Type yCoord = -this->values[2] * vector.values[0] + this->values[0] * vector.values[2];
    Type zCoord = -this->values[0] * vector.values[1] + this->values[1] * vector.values[0];

    Vector<Type> newVector = {xCoord, yCoord, zCoord};
    return newVector;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator^=(const Vector<Type> &vector)
{
    check_sizeforvecmul(vector, __LINE__);

    *this = *this ^ vector;

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::vector_mult(const Vector<Type> &vector) const
{
    return *this ^ vector;
}

template<typename Type>
void Vector<Type>::vector_eq(const Vector<Type> &vector)
{
    *this ^= vector;
}

template<typename Type>
Vector<Type> Vector<Type>::operator/(const Vector<Type> &vector) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0 || vector.count_elem == 0)
    {
        EmpryError(__FILE__, typeid(*this).name(),
                   __LINE__, ctime(&cur_time));
    }

    this->check_sizes(vector, __LINE__);

    return this->vec_div(vector);
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator/(const Vector<Type1> &vector) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        EmpryError(__FILE__, typeid(*this).name(),
                   __LINE__, ctime(&cur_time));
    }

    return this->vec_div(vector);
}



template<typename Type>
Vector<Type> Vector<Type>::operator/(const Type &elem) const
{
    return this->div_el(elem);
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator/(const Type1 &elem) const
{
    return this->div_el(elem);
}


template<typename Type>
Vector<Type> Vector<Type>::vec_divid(const Vector<Type> &vector) const
{
    return *this / vector;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::vec_divid(const Vector<Type1> &vector) const
{
    return *this / vector;
}

template<typename Type>
Type &Vector<Type>::operator[](size_t index)
{
    return at(index);
}

template<typename Type>
const Type &Vector<Type>::operator[](size_t index) const
{
    return at(index);
}

template<typename Type>
bool Vector<Type>::set_elem(size_t index, const Type &vector)
{
    if (index < 0 || index >= this->count_elem)
        return false;

    at(index) = vector;
    return true;
}

template<typename Type>
Vector<Type> Vector<Type>::operator-()
{
    Vector<Type> newVector(*this);
    Iterator<Type> iterator = newVector.begin();
    for (; iterator; iterator++)
    {
        *iterator = -*iterator;
    }

    return newVector;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator=(const Vector<Type> &vector)
{
    this->count_elem = vector.count_elem;
    this->alloc_newvectormem(count_elem);

    Iterator<Type> iteratorTo(*this);
    Iterator<Type> iteratorFrom(vector);
    for (; iteratorTo; iteratorTo++, iteratorFrom++)
    {
        *iteratorTo = *iteratorFrom;
    }

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator=(std::initializer_list<Type> &arguments)
{
    this->count_elem = arguments.size();
    this->alloc_newvectormem(count_elem);

    Iterator<Type> iterator = this->begin();
    for (auto &currentItem : arguments)
    {
        *iterator = currentItem;
        iterator++;
    }

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator=(Vector<Type> &&vector) noexcept
{
    this->count_elem = vector.count_elem;
    this->alloc_newvectormem(count_elem);
    this->values = vector.values;
    vector.values.reset();

    return *this;
}

template<typename Type>
void Vector<Type>::alloc_newvectormem(size_t amount)
{
    time_t cur_time = time(NULL);
    try
    {
        this->values.reset(new Type[amount]);
    }
    catch (std::bad_alloc &exception)
    {
        throw MemoryError(__FILE__, typeid(*this).name(),
                          __LINE__, ctime(&cur_time));
    }
}

template<typename Type>
bool Vector<Type>::is_single() const noexcept
{
    bool ret_out = false;
    if (fabs(this->length<Type>() - 1) < __FLT_EPSILON__)
    {
        ret_out = true;
    }
    return ret_out;
}

template<typename Type>
bool Vector<Type>::is_zero() const noexcept
{
    bool ret_out = false;
    if (this->length<Type>() < __FLT_EPSILON__)
    {
        ret_out = true;
    }

    return ret_out;
}

template<typename Type>
Type Vector<Type>::summary_value()
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    Iterator<Type> iterator = this->begin();
    Type summary = 0;
    for (; iterator; iterator++)
    {
        summary += *iterator;
    }

    return summary;
}

template<typename Type>
template<typename Type1>
Type1 Vector<Type>::length(void) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem == 0)
    {
        throw EmpryError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&cur_time));
    }

    ConstIterator<Type> iterator = this->begin();
    Type sum = 0;
    for (; iterator; iterator++)
    {
        sum += *iterator * *iterator;
    }
    return sqrt(sum);
}

template<typename Type>
Vector<Type> Vector<Type>::negative()
{
    return -*this;
}

template<typename Type>
void Vector<Type>::check_sizes(const Vector<Type> &vector, int num_line) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem != vector.count_elem)
    {
        throw SizeError(__FILE__, typeid(*this).name(),
                        num_line, ctime(&cur_time));
    }
}

template<typename Type>
void Vector<Type>::check_sizeforvecmul(const Vector<Type> &vector, int num_line) const
{
    time_t cur_time = time(NULL);
    if (this->count_elem != 3 || vector.count_elem != 3)
    {
        throw SizeError(__FILE__, typeid(*this).name(),
                        num_line, ctime(&cur_time));
    }
}

template<typename Type>
Vector<Type> operator+(const Type &elem, const Vector<Type> &vector)
{
    return vector + elem;
}

template<typename Type>
Vector<Type> operator-(const Type &elem, const Vector<Type> &vector)
{
    return vector - elem;
}

template<typename Type>
Vector<Type> operator*(const Type &elem, const Vector<Type> &vector)
{
    return vector * elem;
}

template<typename Type>
Vector<Type> operator/(const Type &elem, const Vector<Type> &vector)
{
    return vector / elem;
}

template<typename Type>
std::ostream &operator<<(std::ostream &os, const Vector<Type> &vector)
{
    ConstIterator<Type> iterator = vector.begin();
    if (!iterator)
    {
        os<< "Empty mVector";
        return os;
    }

    os<< "{";
    os<< *iterator;
    for (iterator++; iterator; iterator++)
    {
            os<< ", "<< *iterator;
    }
    os<< "}";

    return os;
}

#endif // VECTOR_H
