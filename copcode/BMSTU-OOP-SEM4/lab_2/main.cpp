#include "MyVector.h"

int main()
{
    MyVector <double> first_array = {1, 2, 3};
    std::cout << "First array: " << first_array << std::endl;
    first_array += 2.0;
    std::cout << "First array after +=2.0 :" << first_array << std::endl;
    std::cout << "First array after +2.0 :" << first_array + 2.0 << std::endl;
    first_array -= 2.0;
    std::cout << "First array after -=2.0 :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after -2.0 :" << first_array - 2.0 << std::endl;
    first_array *= 2.0;
    std::cout << "First array after *=2.0 :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after *2.0 :" << first_array * 2.0 << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    first_array /= 2.0;
    std::cout << "First array after /=2.0 :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after /2.0 :" << first_array / 2.0 << std::endl;
    std::cout << "First array: " << first_array << std::endl;

    std::cout << "--------------" << std::endl;

    first_array = {1, 2, 3};
    std::cout << "First array: " << first_array << std::endl;
    first_array.add(2.0);
    std::cout << "First array after add(2.0) :" << first_array << std::endl;
    std::cout << "First array after +2.0 :" << first_array + 2.0 << std::endl;
    first_array.sub(2.0);
    std::cout << "First array after sub(2.0) :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after -2.0 :" << first_array - 2.0 << std::endl;
    first_array.mul(2.0);
    std::cout << "First array after mul(2.0) :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after *2.0 :" << first_array * 2.0 << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    first_array.div(2.0);
    std::cout << "First array after div(2.0) :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after /2.0 :" << first_array / 2.0 << std::endl;
    std::cout << "First array: " << first_array << std::endl;

    MyVector <int> second_array(3);
    std::cout << "Second array: " << second_array << std::endl;
    MyVector <long double> third_array(3, 3.1415);
    std::cout << "Third array: " << third_array << std::endl;
    MyVector <long double> fourth_array(third_array);
    std::cout << "Fourth array: " << fourth_array << std::endl;

    std::cout << "--------------" << std::endl;
    MyVector <int> unit_vector = {1, 0, 0};
    MyVector <double> unit_vec_sec = {0, 0, 1};
    MyVector <int> col_vec = {2, 0, 0};
    std::cout << "Is Unit: " << unit_vector.is_unit() << std::endl;
    std::cout << "Are Ort: " << unit_vec_sec.areOrthgonal(unit_vec_sec) << std::endl;
    std::cout << "Are Col: " << unit_vector.areCollinear(col_vec) << std::endl;

    std::cout << "--------------" << std::endl;
    MyVector <double> one_vec = {1.45, 2.21, 3.76};
    MyVector <double> sec_vec = {0.31, 0.45, 1.56};
    std::cout << "Are Col: " << one_vec.areCollinear(sec_vec) << std::endl;
    std::cout << "Scalar: " << one_vec.scalarMul(sec_vec) << std::endl;
    double result = one_vec & sec_vec;
    std::cout << "Scalar operator: " << result << std::endl;
    std::cout << "Mul: " << one_vec.vecMul(sec_vec) << std::endl;
    MyVector <double> sec_result = one_vec ^ sec_vec;
    std::cout << "Mul operator: " << sec_result << std::endl;

    MyVector <int> array = {1, 2, 3};
    std::cout << "Int array: " << array << std::endl;
    array += 2.3;
    std::cout << "Int array after +=2.3:" << array << std::endl;
    std::cout << "Int array after +2.4 :" << array + 2.4 << std::endl;
    return 0;
}
