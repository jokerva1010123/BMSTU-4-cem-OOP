#ifndef ERRORS_H
#define ERRORS_H

#include "base_errors.h"

class MemoryError: public BaseMsgError
{
public:
    MemoryError(std::string filename, std::string classname,
                int numberline, const char *time,
                std::string info = "Memory error!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
    virtual const char *what() const noexcept
    {
        return infoerror.c_str();
    }
};

class EmpryError: public BaseMsgError
{
public:
    EmpryError(std::string filename, std::string classname,
               int numberline, const char *time,
               std::string info = "Use empty vector!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
    virtual const char *what() const noexcept
    {
        return infoerror.c_str();
    }
};

class ZerodivError: public BaseMsgError
{
public:
    ZerodivError(std::string filename, std::string classname,
                 int numberline, const char *time,
                 std::string info = "Zero division error!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
    virtual const char *what() const noexcept
    {
        return infoerror.c_str();
    }
};

class DeleteError: public BaseMsgError
{
public:
    DeleteError(std::string filename, std::string classname,
                int numberline, const char *time,
                std::string info = "Work with delete object!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
    virtual const char *what() const noexcept
    {
        return infoerror.c_str();
    }
};

class IndexError: public BaseMsgError
{
public:
    IndexError(std::string filename, std::string classname,
               int numberline, const char *time,
               std::string info = "Index out of range!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
    virtual const char *what() const noexcept
    {
        return infoerror.c_str();
    }
};

class CopyError: public BaseMsgError
{
public:
    CopyError(std::string filename, std::string classname,
              int numberline, const char *time,
              std::string info = "Copy error!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
    virtual const char *what() const noexcept
    {
        return infoerror.c_str();
    }
};

class SizeError: public BaseMsgError
{
public:
    SizeError(std::string filename, std::string classname,
              int numberline, const char *time,
              std::string info = "Vector size error!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
    virtual const char *what() const noexcept
    {
        return infoerror.c_str();
    }
};

class IterError: public BaseMsgError
{
public:
    IterError(std::string filename, std::string classname,
              int numberline, const char *time,
              std::string info = "Iterator error!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
    virtual const char *what() const noexcept
    {
        return infoerror.c_str();
    }
};

#endif // ERRORS_H
