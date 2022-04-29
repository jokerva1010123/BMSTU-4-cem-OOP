#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point() = default;
    Point(const double x,
          const double y,
          const double z);

    Point(const Point &point) = default;
    Point &operator=(const Point &point) = default;

    Point(const Point &&p) noexcept;
    Point &operator=(Point &&point) noexcept;

    bool operator==(const Point &p) const noexcept;
    bool equal(const Point &p) const noexcept;
    bool operator!=(const Point &p) const noexcept;

    ~Point() = default;

    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(const double &x);
    void set_y(const double &y);
    void set_z(const double &z);

    Point operator+(const Point &p);
    Point operator-(const Point &p);

    void move(const double x, const double y, const double z);
    void scale(const double x, const double y, const double z);
    void turn(const double x, const double y, const double z);

    void turn_x(const double &x);
    void turn_y(const double &y);
    void turn_z(const double &z);

    Point add_to(const Point &p);

private:
    double x_, y_, z_;
};

#endif // POINT_H
