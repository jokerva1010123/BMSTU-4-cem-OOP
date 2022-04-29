#include "point.h"
#include <cmath>


double to_rad(const double &alpha)
{
    return alpha * (M_PI / 180);
}

Point::Point(const double x,
             const double y,
             const double z)
    : x_(x), y_(y), z_(z) {}


Point::Point(const Point &&p) noexcept
    : x_(p.x_), y_(p.y_), z_(p.z_)
{
    p.~Point();
}

Point &Point::operator=(Point &&p) noexcept
{
    x_ = p.x_;
    y_ = p.y_;
    z_ = p.z_;

    p.~Point();

    return *this;
}

double Point::get_x() const {
    return x_;
}

double Point::get_y() const {
    return y_;
}

double Point::get_z() const {
    return z_;
}


void Point::set_x(const double &x) {
    x_ = x;
}

void Point::set_y(const double &y) {
    y_ = y;
}

void Point::set_z(const double &z) {
    z_ = z;
}


Point Point::operator+(const Point &p)
{
    Point pp{*this};

    pp.set_x(pp.x_ + p.x_);
    pp.set_y(pp.y_ + p.y_);
    pp.set_z(pp.z_ + p.z_);

    return pp;
}

Point Point::operator-(const Point &p)
{
    Point pp{*this};

    pp.set_x(pp.x_ - p.x_);
    pp.set_y(pp.y_ - p.y_);
    pp.set_z(pp.z_ - p.z_);

    return pp;
}

Point Point::add_to(const Point &p)
{
    return *this + p;
}

//void Point::move(const double x, const double y, const double z)
//{
//    x_ += x;
//    y_ += y;
//    z_ += z;
//}

//void Point::scale(const double x, const double y, const double z)
//{
//    x_ *= x;
//    y_ *= y;
//    z_ *= z;
//}

//void Point::turn(const double x, const double y, const double z)
//{
//    turn_x(x);
//    turn_y(y);
//    turn_z(z);
//}

//void Point::turn_x(const double &x)
//{
//    double cos_ = cos(to_rad(x));
//    double sin_ = sin(to_rad(x));

//    double buf  = y_;

//    y_ = y_ * cos_ + z_ * sin_;
//    z_ = -buf *sin_ + z_ * cos_;
//}

//void Point::turn_y(const double &y)
//{
//    double cos_ = cos(to_rad(y));
//    double sin_ = sin(to_rad(y));

//    double buf  = x_;

//    x_ = x_ * cos_ + z_ * sin_;
//    z_ = -buf * sin_ + z_ * cos_;
//}

//void Point::turn_z(const double &z)
//{
//    double cos_ = cos(to_rad(z));
//    double sin_ = sin(to_rad(z));

//    double buf  = x_;

//    x_ = x_ * cos_ + y_ * sin_;
//    y_ = -buf * sin_ + y_ * cos_;
//}

void Point<double>::reform(const std::shared_ptr<Matrix<double>> matrix)
{
    std::vector<double> res(4, 0);
    std::vector<double> data = {this->px, this->py, this->px, 1};

    for (size_t i = 0; i < 4; ++i)
    {
        for (size_t j = 0; j < 4; ++j)
        {
            res[i] += data[j] * (*matrix)[i][j];
        }
    }


    this->set_x(res[0]);
    this->set_y(res[1]);
    this->set_z(res[2]);
}


bool Point::operator==(const Point &p) const noexcept
{
    return (p.x_ == x_) && (p.y_ == y_) && (p.z_ == z_);
}

bool Point::equal(const Point &p) const noexcept
{
    return *this == p;
}

bool Point::operator!=(const Point &p) const noexcept
{
    return !(*this == p);
}

