#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "BaseException.h"

class MemoryError: public BaseException
{
    public:
        MemoryError(std::string filename, std::string classname,
                    int current_line, const char *time,
                    std::string information = "Memory Error"):
        BaseException(filename, classname, current_line, time, information){};
};

class ZeroDivisionError: public BaseException
{
    public:
        ZeroDivisionError(std::string filename, std::string classname,
                    int current_line, const char *time,
                    std::string information = "Division by 0"):
        BaseException(filename, classname, current_line, time, information){};
};

class OutRangeError: public BaseException
{
    public:
        OutRangeError(std::string filename, std::string classname,
                    int current_line, const char *time,
                    std::string information = "Out of range"):
        BaseException(filename, classname, current_line, time, information){};
};



#endif // EXCEPTION_H
