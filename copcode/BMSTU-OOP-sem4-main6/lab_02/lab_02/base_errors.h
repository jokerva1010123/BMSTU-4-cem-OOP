#ifndef BASE_ERROR_H
#define BASE_ERROR_H

#include <exception>
#include <iostream>

class BaseMsgError: public std::exception
{
public:
    BaseMsgError(std::string filename,
                 std::string classname,
                 int numberline,
                 const char *time,
                 std::string info);

    // Модификатор override может использоваться с любым методом, который должен быть переопределением
    // Спецификатор noexcept определяет функцию как не выбрасывающую исключений
    virtual const char *what() const noexcept override;

    virtual ~BaseMsgError() {}

protected:
    std::string infoerror;
};

#include "base_errors.cpp"

#endif // BASE_ERROR_H
