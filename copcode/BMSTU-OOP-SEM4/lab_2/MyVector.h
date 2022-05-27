#ifndef MyVector_H
#define MyVector_H

#include <iostream>
#include <memory>
#include <type_traits>
#include <cmath>

#include "Iterator.h"
//#include "ConstIterator.h"
#include "BaseVector.h"

template<typename Type>
class MyVector: public BaseVector
{
    private:
        std::shared_ptr<Type[]> array;

    protected:
        void allocate_memory(size_t count); //+
        template<typename Type_2> void check_vector_sizes(const MyVector<Type_2> &vector, int line) const; //+
        void checkSizesForVecMul(const MyVector<Type> &vector, int lineError) const; //+
        Type sumElems(); //Для скалярного произведения //+

    public:
        friend class Iterator<Type>; //+
      //  friend class ConstIterator<Type>; //+

        // Конструкторы
        MyVector(); //+
        explicit MyVector(size_t size); //+
        MyVector(size_t size, const Type *arrayFrom); //+
        MyVector(size_t size, Type element); //+
        MyVector(const std::initializer_list<Type> &elements); //+
        explicit MyVector(const MyVector<Type> &vector); //+
        MyVector(MyVector<Type> &&vector) noexcept; //+

        // Деструктор
        virtual ~MyVector() = default; //+)

        // Варианты оператора присвоения
        MyVector<Type> &operator=(const MyVector<Type> &vector); //+
        MyVector<Type> &operator=(const std::initializer_list<Type> &arguments); //+
        MyVector<Type> &operator=(MyVector<Type> &&vector); //+

        // Варианты метода at и перегрузка оператора индексации
        Type &at(size_t index); //+
        const Type &at(size_t index) const; //+
        Type &operator[](size_t index);  //+
        const Type &operator[](size_t index) const; //+

        // Булевы операции для сравнения векторов и определения типа вектора
        bool operator==(const MyVector<Type> &vector) const; //+
        bool is_equal(const MyVector<Type> &vector) const; //+
        bool operator!=(const MyVector<Type> &vector) const; //+
        bool is_not_equal(const MyVector<Type> &vector) const; //+
        bool is_zero() const noexcept; //+
        bool is_unit() const noexcept; //+

        // Методы работы с одним вектором: узнать модуль и найти коллинеарный единичный
        template<typename TypeOut> TypeOut geomLength() const; //+
        template<typename TypeOut> MyVector<TypeOut> find_unit_vector() const;


        // Методы для взаимного определения двух векторов
        double angle(const MyVector<Type> &another) const; //+
        bool areCollinear(const MyVector<Type> &another) const; //+
        bool areOrthgonal(const MyVector<Type> &another) const; //+

        MyVector<Type> operator-(); //+
        MyVector<Type> negative(); //+

        template<typename Type_2> MyVector<Type> &operator+=(const MyVector<Type_2> &vector); //+
        template<typename Type_2> MyVector<Type> &operator+=(const Type_2 &element); //+
        template<typename Type_2> void add(const MyVector<Type_2> &vector); //+
        template<typename Type_2> void add(const Type_2 &element); //+
        template<typename Type_2> MyVector<Type> operator+(const MyVector<Type_2> &vector) const; //+
        template<typename Type_2> MyVector<Type> operator+(const Type_2 &element) const; //+
        template<typename Type_2> MyVector<Type> sum_two_vectors(const MyVector<Type_2> &vector) const; //+
        template<typename Type_2> MyVector<Type> sum_vector_and_elem(const Type_2 &element) const; //+

        template<typename Type_2> MyVector<Type> &operator-=(const MyVector<Type_2> &vector); //+
        template<typename Type_2> MyVector<Type> &operator-=(const Type_2 &element); //+
        template<typename Type_2> void sub(const MyVector<Type_2> &vector); //+
        template<typename Type_2> void sub(const Type_2 &element); //+
        template<typename Type_2> MyVector<Type> operator-(const MyVector<Type_2> &vector) const; //+
        template<typename Type_2> MyVector<Type> operator-(const Type_2 &element) const; //+
        template<typename Type_2> MyVector<Type> sub_two_vectors(const MyVector<Type_2> &vector) const; //+
        template<typename Type_2> MyVector<Type> sub_vector_and_elem(const Type_2 &element) const; //+

        template<typename Type_2> MyVector<Type> &operator*=(const MyVector<Type_2> &vector); //+
        template<typename Type_2> MyVector<Type> &operator*=(const Type_2 &element); //+
        template<typename Type_2> void mul(const MyVector<Type_2> &vector); //+
        template<typename Type_2> void mul(const Type_2 &element); //+
        template<typename Type_2> MyVector<Type> operator*(const MyVector<Type_2> &vector) const; //+
        template<typename Type_2> MyVector<Type> operator*(const Type_2 &element) const; //+
        template<typename Type_2> MyVector<Type> mul_two_vectors(const MyVector<Type_2> &vector) const; //+
        template<typename Type_2> MyVector<Type> mul_vector_and_elem(const Type_2 &element) const; //+

        template<typename Type_2> MyVector<Type> &operator/=(const MyVector<Type_2> &vector); //+
        template<typename Type_2> MyVector<Type> &operator/=(const Type_2 &element); //+
        template<typename Type_2> void div(const MyVector<Type_2> &vector); //+
        template<typename Type_2> void div(const Type_2 &element); //+
        template<typename Type_2> MyVector<Type> operator/(const MyVector<Type_2> &vector) const; //+
        template<typename Type_2> MyVector<Type> operator/(const Type_2 &element) const; //+
        template<typename Type_2> MyVector<Type> div_two_vectors(const MyVector<Type_2> &vector) const; //+
        template<typename Type_2> MyVector<Type> div_vector_and_elem(const Type_2 &element) const; //+

        Type operator&(const MyVector<Type> &vector) const; //+
        Type scalarMul(const MyVector<Type> &vector) const; //+

        MyVector<Type> operator^(const MyVector<Type> &vector) const; //+
        MyVector<Type> vecMul(const MyVector<Type> &vector) const; //+
        MyVector<Type> &operator^=(const MyVector<Type> &vector); //+

        // Методы для итераторов
        Iterator<Type> begin() const noexcept; //+
        Iterator<Type> end() const noexcept; //+
        Iterator<Type> begin() noexcept; //+
        Iterator<Type> end() noexcept; //+
        Iterator<Type> constBegin() const noexcept; //+
        Iterator<Type> constEnd() const noexcept; //+

};

#include "MyVector.hpp"

#endif // MyVector_H
