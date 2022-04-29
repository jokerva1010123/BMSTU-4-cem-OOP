#ifndef LINKS_H
#define LINKS_H

#include <cstddef>

class Link
{
public:
    Link() = default;
    Link(const size_t &p1, const size_t &p2);
    Link(const Link &l) = default;

    ~Link() = default;

    size_t get_p1() const;
    size_t get_p2() const;

    void set_p1(const size_t &p1);
    void set_p2(const size_t &p2);

private:
    size_t p1_i;
    size_t p2_i;
};

#endif // LINKS_H
