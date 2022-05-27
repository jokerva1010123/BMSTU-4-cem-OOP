#ifndef class_Vector_h
#define class_Vector_h

#include <stdarg.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <stdexcept>
#include <string.h>

#include "BaseVector.h"
#include "Iterator.h"

#define EPS 1e-5

template<typename Type>
class Vector: public BaseVector
{
    public:
        friend class Iterator<Type>;

        //конструкторы
        Vector();
        explicit Vector(int num_elements);
        Vector(int num_elements, Type* vec);
        Vector(int num_elements, Type vec, ...);
        Vector(std::initializer_list<Type> args);
        explicit Vector(const Vector<Type> &vec);
        Vector(Vector<Type>&& vec) noexcept;

        //Деструктор
        ~Vector();

        //Операторы присваивания
        Vector<Type>& operator =(const Vector<Type>& vec);
        Vector<Type>& operator =(Vector<Type> &&vec) noexcept;
        Vector<Type>& operator =(std::initializer_list<Type> args);

        //Операторы сложения
        Vector<Type> operator +(const Vector<Type>&) const;
        Vector<Type> sum(const Vector<Type> &) const;
        Vector<Type>& operator +=(const Vector<Type>&);
        Vector<Type>& sumEqual(const Vector<Type> &);

        //Операторы вычитания
        Vector<Type> operator -(const Vector<Type>&) const;
        Vector<Type> sub(const Vector<Type> &) const;
        Vector<Type>& operator -=(const Vector<Type>&);
        Vector<Type>& subEqual(const Vector<Type> &);

        //Оператор умножения на число
        Vector<Type> operator *(const Type& mult) const;
        Vector<Type> mulNum(const Type& mult) const;
        Vector<Type>& operator *=(const Type& mult);
        Vector<Type>& mulNumEqual(const Type& mult);

        //Оператор деления на число
        Vector<Type> operator /(const Type& div) const;
        Vector<Type> divNum(const Type& div) const;
        Vector<Type>& operator /=(const Type& div);
        Vector<Type>& divNumEqual(const Type& div);

        //Оператор векторного произведения
        Vector<Type> operator &(const Vector<Type>& vec);
        Vector<Type> vectorMul(const Vector<Type>& vec);
        Vector<Type>& operator &=(const Vector<Type>& vec);
        Vector<Type>& vectorMulEqual(const Vector<Type>& vec);

        //Оператор скалярного произведения
        Type operator *(const Vector<Type>& vec) const;
        Type scalarMul(const Vector<Type>& vec) const;

        //Оператор произведения по элеметам
        Vector<Type> operator ^(const Vector<Type> & vec) const;
        Vector<Type> mulElement(const Vector<Type> & vec) const;
        Vector<Type>& operator ^=(const Vector<Type> & vec);
        Vector<Type>& mulElementEqual(const Vector<Type> & vec);

        Vector<Type> operator -();
        Vector<Type> neg();

        bool operator ==(const Vector<Type>&) const;
        bool operator !=(const Vector<Type>&) const;
        bool isEqual(const Vector<Type>&) const;
        bool isNotEqual(const Vector<Type>&) const;

        Type& operator [](int index);
        const Type& operator [](int index) const;
        Type& get_elem_Vector(int index);
        const Type& get_elem_Vector(int index) const;
        bool set_elem_Vector(int index, const Type& vec);

        bool is_zero() const;
        bool is_single() const;
        int size() const;
        Type len() const;

        Vector<Type> get_single_vector() const;
        double angle_between_vectors(const Vector<Type>&) const;
        bool is_collinearity(const Vector<Type>&) const;
        bool is_orthogonality(const Vector<Type>&) const;

        Iterator<Type> begin() noexcept;
        Iterator<Type> end() noexcept;
        Iterator<Type> begin() const noexcept;
        Iterator<Type> end() const noexcept;
        Iterator<Type> constBegin() const noexcept;
        Iterator<Type> constEnd() const noexcept;

    private:
        std::shared_ptr<Type[]> data_list;

    protected:
        Type sum_all_elem();
        void sum_vectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const;
        void difference_vectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const;
        void mult_vectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const;
        void new_dyn_mem(int);
};

template<typename Type>
std::ostream& operator <<(std::ostream& os, const Vector<Type>& vec)
{
    Iterator<Type> iter(vec);

    if (!iter)
    {
        os << "Vector is empty.";
        return os;
    }

    os << '(' << *iter;
    for (iter++; iter; iter++)
        os << ", " << *iter ;
    os << ')';

    return os;
}

#endif
