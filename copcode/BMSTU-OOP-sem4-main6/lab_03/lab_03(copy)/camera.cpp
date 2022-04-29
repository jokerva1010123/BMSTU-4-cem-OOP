#include "camera.h"
#include "matrix_trans.h"

//void Camera::moveX(const double &s)
//{
//    cur_p.set_x(cur_p.get_x() + s);
//}

//void Camera::moveY(const double &s)
//{
//    cur_p.set_y(cur_p.get_y() + s);
//}

//void Camera::moveZ(const double &s)
//{
//    cur_p.set_z(cur_p.get_z() + s);
//}

void Camera::reform(const Point &np, const Point &s, const Point &t)
{
    std::shared_ptr<Matrix<double>> transform_matrix(std::make_shared<MatrixMove>(np.get_x(), np.get_y(), np.get_z()));
//    moveX(np.get_x());
//    moveY(np.get_y());

    cur_p.reform(transform_matrix);
}

void Camera::accept(std::shared_ptr<Visitor> v)
{
    v->visit(*this);
}
