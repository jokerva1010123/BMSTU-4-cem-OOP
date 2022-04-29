#ifndef MATRIX_TRANS_H
#define MATRIX_TRANS_H

#include <cmath>
#include "matrix.hpp"
#include "point.h"

class MatrixMove: public Matrix<double>
{
public:
    MatrixMove(double x, double y, double z);
};

class MatrixTurnX: public Matrix<double>
{
public:
    MatrixTurnX(double alpha);
};

class MatrixTurnY: public Matrix<double>
{
public:
    MatrixTurnY(double alpha);
};

class MatrixTurnZ: public Matrix<double>
{
public:
    MatrixTurnZ(double alpha);
};

class MatrixScale: public Matrix<double>
{
public:
    MatrixScale(double x, double y, double z);
};



#endif // MATRIX_TRANS_H
