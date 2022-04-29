#include "matrix_trans.h"


MatrixMove::MatrixMove(double x, double y, double z)
    : Matrix<double>(4, 4, 0)
{
    (*this)[0][0] = 1;
    (*this)[1][1] = 1;
    (*this)[2][2] = 1;
    (*this)[3][3] = 1;
    (*this)[0][3] = x;
    (*this)[1][3] = y;
    (*this)[2][3] = z;
}

MatrixScale::MatrixScale(double x, double y, double z)
    : Matrix<double>(4, 4, 0)
{
    (*this)[0][0] = x;
    (*this)[1][1] = y;
    (*this)[2][2] = z;
    (*this)[3][3] = 1;
}

MatrixTurnX::MatrixTurnX(double alpha)
    : Matrix<double>(4, 4, 0)
{
    (*this)[0][0] = 1;
    (*this)[1][1] = cos(alpha);
    (*this)[1][2] = -sin(alpha);
    (*this)[2][1] = sin(alpha);
    (*this)[2][2] = cos(alpha);
    (*this)[3][3] = 1;
}

MatrixTurnY::MatrixTurnY(double alpha)
    : Matrix<double>(4, 4, 0)
{
    (*this)[0][0] = cos(alpha);
    (*this)[1][1] = 1;
    (*this)[2][0] = -sin(alpha);
    (*this)[0][2] = sin(alpha);
    (*this)[2][2] = cos(alpha);
    (*this)[3][3] = 1;
}

MatrixTurnZ::MatrixTurnZ(double alpha)
    : Matrix<double>(4, 4, 0)
{
    (*this)[0][0] = cos(alpha);
    (*this)[0][1] = -sin(alpha);
    (*this)[1][0] = sin(alpha);
    (*this)[1][1] = cos(alpha);
    (*this)[2][2] = 1;
    (*this)[3][3] = 1;
}
