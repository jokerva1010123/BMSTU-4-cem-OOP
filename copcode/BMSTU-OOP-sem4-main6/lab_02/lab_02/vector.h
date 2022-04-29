#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>

#include "base_vector.h"
#include "const_iterator.h"
#include "iterator.h"

// class Vector
template<typename Type>
class Vector: public BaseVector
{
public:
    friend class Iterator<Type>;
    friend class ConstIterator<Type>;

    // Конструкторы
    Vector();

    // Ключевое слово explicit делает этот конструктор закрытым для выполнения любых неявных конвертаций
    explicit Vector(size_t size);
    Vector(size_t size, Type elem, ...);
    Vector(size_t size, const Type *array);
    Vector(std::initializer_list<Type> elem);
    explicit Vector(const Vector<Type> &vector); // копирование !!!
    Vector(Vector<Type> &&vector) noexcept; // перемещение !!!
    template <typename Type_>
    Vector(Type_ begin, Type_ end); // через итераторы !!!

    // Деструктор
    virtual ~Vector() = default;

    // Копирование и перенос
    Vector<Type> operator=(std::initializer_list<Type> &arg); //  убрать & и конст !!!
    Vector<Type> &operator=(const Vector<Type> &vector); // присваивание копированием
    Vector<Type> &operator=(Vector<Type> &&vector) noexcept; // присваивание перемещением

    bool is_single() const noexcept;
    bool is_zero() const noexcept;

    // взять элемент с позиции index
    Type &at(size_t index);
    const Type &at(size_t index) const;

    Type &operator[](size_t index);
    const Type &operator[](size_t index) const;

    // поставить элемент в index
    bool set_elem(size_t index, const Type &elem);

    // Методы для одного вектора
    template<typename Type1>
    Type1 length() const; // модуль вектора |a|
    template<typename Type1>
    Vector<Type1> get_unit() const; // нормарование вектора a/|a| !!!


    // Методы для двух векторов
    bool collinear_vectors(const Vector<Type> &vector) const;
    bool orthgonal_vectors(const Vector<Type> &vector) const;
    double angle(const Vector<Type> &vector) const;


    // Итераторы
    ConstIterator<Type> begin() const noexcept;
    ConstIterator<Type> end() const noexcept;
    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;
    ConstIterator<Type> cBegin() const noexcept;
    ConstIterator<Type> cEnd() const noexcept;

    // Операторы
    // создается новый вектор
    Vector<Type> operator+(const Type &elem) const; // прибавить к вектору число
    Vector<Type> operator+(const Vector<Type> &vector) const; // прибавить вектор к вектору
    Vector<Type> vec_sum(const Vector<Type> &vector) const; // сумма векторов
    Vector<Type> sum_el(const Type &element) const; // сумма вектора и элемента
    // изменяется старый
    Vector<Type> &operator+=(const Type &elem);
    Vector<Type> &operator+=(const Vector<Type> &vector);
    void sum_eq(const Vector<Type> &vector);
    void sum_eq(const Type &elem);

    template<typename Type1>
    decltype(auto) operator+(const Type1 &elem) const;
    template<typename Type1>
    decltype(auto) operator+(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) vec_sum(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) sum_el(const Type1 &element) const;


    Vector<Type> operator-(const Type &elem) const;
    Vector<Type> operator-(const Vector<Type> &vector) const;
    Vector<Type> vec_dif(const Vector<Type> &vector) const;
    Vector<Type> dif_el(const Type &element) const;
    Vector<Type> &operator-=(const Type &elem);
    Vector<Type> &operator-=(const Vector<Type> &vector);
    void dif_eq(const Vector<Type> &vector);
    void dif_eq(const Type &elem);

    template<typename Type1>
    decltype(auto) operator-(const Type1 &elem) const;
    template<typename Type1>
    decltype(auto) operator-(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) vec_dif(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) dif_el(const Type1 &element) const;


    Vector<Type> operator*(const Type &elem) const; // умножить вектор  на число (каждый элемент)
    Vector<Type> operator*(const Vector<Type> &vector) const; // вектор умножить на вектор по элементно
    Vector<Type> vec_multip(const Vector<Type> &vector) const;
    Vector<Type> mul_el(const Type &element) const;
    Vector<Type> &operator*=(const Type &elem);
    Vector<Type> &operator*=(const Vector<Type> &vector);
    void mul_eq(const Vector<Type> &vector);
    void mul_eq(const Type &elem);

    template<typename Type1>
    decltype(auto) operator*(const Type1 &elem) const;
    template<typename Type1>
    decltype(auto) operator*(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) vec_multip(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) mul_el(const Type1 &element) const;


    Vector<Type> operator/(const Type &elem) const; // поделить вектор на число (каждый элемент)
    Vector<Type> operator/(const Vector<Type> &vector) const; // вектор на вектор поделить по элементно
    Vector<Type> vec_divid(const Vector<Type> &vector) const;
    Vector<Type> div_el(const Type &element) const;
    Vector<Type> &operator/=(const Type &elem);
    Vector<Type> &operator/=(const Vector<Type> &vector);
    void div_eq(const Vector<Type> &vector);
    void div_eq(const Type &element);

    template<typename Type1>
    decltype(auto) operator/(const Type1 &elem) const;
    template<typename Type1>
    decltype(auto)  operator/(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) vec_divid(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) div_el(const Type1 &element) const;


    Vector<Type> operator^(const Vector<Type> &vector) const; // векторное произведение (так как 2 векора, то размерность 3)
    Vector<Type> &operator^=(const Vector<Type> &vector);
    Vector<Type> vector_mult(const Vector<Type> &vector) const;
    void vector_eq(const Vector<Type> &vector);

    Type operator&(const Vector<Type> &vector) const; // скалярное произведение
    Type scalar_mult(const Vector<Type> &vector) const;

    bool operator!=(const Vector<Type> &vector) const;
    bool operator==(const Vector<Type> &vector) const;
    bool is_equal(const Vector<Type> &vector) const;
    bool is_not_equal(const Vector<Type> &vector) const;

    Vector<Type> operator-();
    Vector<Type> negative();

private:
    std::shared_ptr<Type[]> values;

protected:
    Type summary_value();

    Vector<Type> vec_mul(const Vector<Type> &vector) const;
    template<typename Type1>
    decltype(auto) vec_mul(const Vector<Type1> &vector) const;

    Vector<Type> vec_div(const Vector<Type> &vector) const;
    template<typename Type1>
    decltype(auto) vec_div(const Vector<Type1> &vector) const;

    void check_sizes(const Vector<Type> &vector, int lineError) const;
    void check_sizeforvecmul(const Vector<Type> &vector, int lineError) const;
    void alloc_newvectormem(size_t itemsAmount);
};

#include "vector.hpp"

#endif // VECTOR_H
