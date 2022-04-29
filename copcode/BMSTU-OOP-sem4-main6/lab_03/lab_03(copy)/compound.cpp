#include "compound.h"
#include "matrix_trans.h"

Compound::Compound(std::vector<Point> &p, std::vector<Link> &l)
    : center_{}, point_(p), link_(l) {}

Compound::Compound(Point &c, std::vector<Point> &p, std::vector<Link> &l)
    : center_(c), point_(p), link_(l) {}


const Point &Compound::get_center() const
{
    return center_;
}

const std::vector<Point> &Compound::get_point() const
{
    return point_;
}

const std::vector<Link> &Compound::get_link() const
{
    return link_;
}

void Compound::reform(const Point &m,
                      const Point &s,
                      const Point &t)
{
    std::shared_ptr<Matrix<double>> transform_matrix(std::make_shared<MatrixMove>(m.get_x(), m.get_y(), m.get_z()));
    std::shared_ptr<Matrix<double>> transform_matrix_s(std::make_shared<MatrixScale>(s.get_x(), s.get_y(), s.get_z()));
    std::shared_ptr<Matrix<double>> transform_matrix_tx(std::make_shared<MatrixTurnX>(t.get_x()));
    std::shared_ptr<Matrix<double>> transform_matrix_ty(std::make_shared<MatrixTurnY>(t.get_y()));
    std::shared_ptr<Matrix<double>> transform_matrix_tz(std::make_shared<MatrixTurnZ>(t.get_z()));
    center_.reform(transform_matrix);

    for (auto &p : point_)
    {
        p.reform(transform_matrix_s);
        p.reform(transform_matrix_tx);
        p.reform(transform_matrix_ty);
        p.reform(transform_matrix_tz);


    }
}
