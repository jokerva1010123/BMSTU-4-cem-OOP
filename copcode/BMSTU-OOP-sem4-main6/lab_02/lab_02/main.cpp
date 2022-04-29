#include <iostream>
#include "vector.h"
#include "defines.h"

int main(void)
{
    Vector<double> initializerListExample = {1, 2, 3};
    Vector<float> lenExample(3);
    Vector<double> lenFillExample(3, 6.66, 1., 2.);
    Vector<long double> emptyVector(0);
    Vector<int> diffVector(5, 1, 2, 3, 4, 5);
    Vector<int> simpl_vector = {1, 2, 3, 4, 5};
    Vector<int>simpl_vector2(simpl_vector.begin(), simpl_vector.end());

    Vector<double> v12{1., 2., 3., 4., 5.};
    std::cout << "\nInit vector {1., 2., 3., 4., 5.}: " << v12 << "\n";
    v12[2] = 10.;
    std::cout << "Change third element using []: " << v12 << "\n";
    v12.set_elem(3, 11.);
    std::cout << "Change fourth element using set_elem_Vector method: " << v12 << "\n";
    v12 = v12.get_unit<double>();
    std::cout << "Get vector with lenght of one: " << v12 << "\n\n";

    std::cout<< "initializerListInit: "<< initializerListExample<< std::endl;
    std::cout<< "lenInit: "<< lenExample<< std::endl;
    std::cout<< "LenFillInit with 6.66 filler: "<< lenFillExample<< std::endl;
    std::cout<< "Empty vector: "<< emptyVector<< std::endl;
    std::cout<< "Simple vector: "<< simpl_vector<< std::endl;
    std::cout<< "Simple vector copy with iterator: "<< simpl_vector2<< std::endl;
    std::cout<< "Diff vector: "<< diffVector<< std::endl;

    Vector<int> operVecF = {1, 2, 1};
    Vector<int> operVecS = {3, 2, 4};

    std::cout<< "\nLenFill and InitList angle: "<< lenFillExample.angle(initializerListExample)<< std::endl;

    std::cout<< "\nFor vectors: "<< operVecF<< " and "<< operVecS<< std::endl;
    std::cout<< "Vectors *: "<< operVecF * operVecS<< std::endl;
    std::cout<< "Vectors /: "<< operVecF / operVecS<< std::endl;
    std::cout<< "Vectors +: "<< operVecF + operVecS<< std::endl;
    std::cout<< "Vectors -: "<< operVecF - operVecS<< std::endl;

    Vector<float> orthVecF = {1, 0, 0};
    Vector<float> orthVecS = {0, 1, 0};
    Vector<float> nonOrthVec = {1, 2, 3};

    std::cout<< "\nShould be orth: "<< orthVecF.orthgonal_vectors(orthVecS)<< std::endl;
    std::cout<< "Shouldn't be orth: "<<orthVecF.collinear_vectors(nonOrthVec)<< std::endl;

    Vector<int> colVecF = {1, 0, 0};
    Vector<int> colVecS = {1, 0, 0};

    std::cout<< "\nShould be coll: "<< colVecF.collinear_vectors(colVecS)<< std::endl;
    std::cout<< "Shouldn't be coll: "<< colVecF.collinear_vectors(operVecF)<< std::endl;

    try {
        orthVecF.collinear_vectors(lenExample);
    } catch (BaseMsgError &err) {
        std::cout<< "Error catch:"<< err.what()<< std::endl;
    }

    std::cout<< "\nVector "<< colVecS<< " length is: "<< colVecS.length<float>()<<std::endl;

    std::cout<< "\nAt 1 el of vector "<< nonOrthVec<< " we have "<< nonOrthVec.at(1)<<std::endl;
    std::cout<< "At 2 el of vector "<< nonOrthVec<< " we have "<< nonOrthVec.at(2)<<std::endl;

    try {
        std::cout<< "At 5 el of vector "<< nonOrthVec<< " we have\n"<< nonOrthVec.at(5)<<std::endl;
    } catch (BaseMsgError &err) {
        std::cout<< "Error catch:"<< err.what()<< std::endl;
    }

    Vector<double> unitVector = nonOrthVec.get_unit<double>();
    std::cout<< "\nUnit vector for "<< nonOrthVec<< " is vector "<< unitVector<< std::endl;

    std::cout<< "\nIs vector "<< unitVector<< " unit? Answer: "<< unitVector.is_single()<< std::endl;
    std::cout<< "Is vector "<< nonOrthVec<< " unit? Answer: "<< nonOrthVec.is_single()<< std::endl;

    std::cout<< "\nIs vector "<< nonOrthVec<< " zero? Answer: "<< nonOrthVec.is_zero()<< std::endl;
    std::cout<< "Is vector "<< lenExample<< " zero? Answer: "<< lenExample.is_zero()<< std::endl;

    std::cout<< "\nIncrement to all coords 2 of "<< nonOrthVec<< " is: "<< nonOrthVec.sum_el(2)<<std::endl;
    std::cout<< "Decrement to all coords 2 of "<< nonOrthVec<< " is: "<< nonOrthVec.dif_el(2)<<std::endl;
    std::cout<< "Div to all coords 4 of "<< nonOrthVec<< " is: "<< nonOrthVec.div_el(4)<<std::endl;
    std::cout<< "Mul to all coords 4 of "<< nonOrthVec<< " is: "<< nonOrthVec.mul_el(4)<<std::endl;

    std::cout<< "\nFor each: ";
    for (auto elem:orthVecF)
        std::cout<< elem<< " ";

    std::cout<< "\nFor each &: ";
    for (auto &elem:orthVecF)
        std::cout<< elem<< " ";

    std::cout<< "\nFor each const &: ";
    for (const auto &elem:orthVecF)
        std::cout<< elem<< " ";

    std::cout<< "\nNonNeg: "<< nonOrthVec<< std::endl;
    nonOrthVec = nonOrthVec.negative();
    std::cout<< "Neg: "<< nonOrthVec<< std::endl;

    nonOrthVec += 1;
    std::cout<< "+= 1 "<< nonOrthVec<< std::endl;

    nonOrthVec -= 1;
    std::cout<< "-= 1 "<< nonOrthVec<< std::endl;

    nonOrthVec *= 2;
    std::cout<< "*= 2 "<< nonOrthVec<< std::endl;

    nonOrthVec /= 2;
    std::cout<< "/= 2 "<< nonOrthVec<< std::endl;

    std::cout<< "The same with phrases... "<< std::endl;

    nonOrthVec.sum_eq(1);
    std::cout<< "+= 1 "<< nonOrthVec<< std::endl;

    nonOrthVec.dif_eq(1);
    std::cout<< "-= 1 "<< nonOrthVec<< std::endl;

    nonOrthVec.mul_eq(2);
    std::cout<< "*= 2 "<< nonOrthVec<< std::endl;

    nonOrthVec.div_eq(2);
    std::cout<< "/= 2 "<< nonOrthVec<< std::endl;

    std::cout<< nonOrthVec<< " + 3 = "<< nonOrthVec + float(3)<< std::endl;
    std::cout<< nonOrthVec<< " - 3 = "<< nonOrthVec - float(3)<< std::endl;
    std::cout<< nonOrthVec<< " / 3 = "<< nonOrthVec / float(3)<< std::endl;
    std::cout<< nonOrthVec<< " * 3 = "<< nonOrthVec * float(3)<< std::endl;

    std::cout<< "\nInit with \"int arr[2] = {1, 2};\""<< std::endl;
    int arr[2] = {1, 2};
    Vector<int> arrVec(2, arr);
    std::cout<< arrVec<< std::endl << std::endl;

    Vector<int> vec = {1, 2, 3};
    Vector<int> vecdel = {3, 2, 1};
    std::cout<< vecdel << " ^= "<< vec << " = ";
    vecdel ^= vec;
    std::cout<< vecdel << std::endl << std::endl;

    Vector<int> vec1 = {1, 2, 3};
    Vector<double> vec2 = {0.5, 2, 1};
    std::cout<< vec2 << " + " << vec1 << " = " << vec2 + vec1 << std::endl << std::endl;
    std::cout<< vec2 << " - " << vec1 << " = " << vec2 - vec1 << std::endl << std::endl;
    std::cout<< vec2 << " * " << vec1 << " = " << vec2 * vec1 << std::endl << std::endl;
    std::cout<< vec2 << " / " << vec1 << " = " << vec2 / vec1 << std::endl << std::endl;

    std::cout<< vec1 << " + 1.56 " << " = ";
    std::cout<< vec1 + 1.56 << std::endl << std::endl;
    std::cout<< vec1 << " - 1.56 " << " = ";
    std::cout<< vec1 - 1.56 << std::endl << std::endl;
    std::cout<< vec1 << " * 1.56 " << " = ";
    std::cout<< vec1 * 1.56 << std::endl << std::endl;
    std::cout<< vec1 << " / 1.56 " << " = ";
    std::cout<< vec1 / 1.56 << std::endl << std::endl;

    return OK;
}
