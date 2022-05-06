#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <iostream>
#include <exception>

class BaseException: public std::exception
{
    public:
        BaseException(std::string fileName, std::string className,
                      int currentLine, const char *errorTime, std::string information);
        virtual const char *what() const noexcept override;

        virtual ~BaseException(){}
    private:
        std::string information;
};

#endif // BASEEXCEPTION_H
