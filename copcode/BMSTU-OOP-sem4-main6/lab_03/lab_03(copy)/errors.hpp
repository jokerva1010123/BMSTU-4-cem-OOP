#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <exception>
#include <string>

class BaseMsgError: public std::exception
{
public:
    explicit BaseMsgError(std::string filename,
                          std::string classname,
                          int numberline,
                          const char *time,
                          std::string info)
    {
        infoerror = "\n\nFile: " + filename +
                    "\nClass: " + classname +
                    "\nLine: " + std::to_string(numberline) +
                    "\nTime: " + time +
                    "\nInfo: " + info;
    }

    // Модификатор override может использоваться с любым методом, который должен быть переопределением
    // Спецификатор noexcept определяет функцию как не выбрасывающую исключений
    const char *what() const noexcept override
    {
        return infoerror.c_str();
    }

protected:
    std::string infoerror;
};

class DrawError: public BaseMsgError
{
public:
    DrawError(std::string filename,
              std::string classname,
              int numberline,
              const char *time,
              std::string info = "Drawer was not add or set!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
};

class CameraError: public BaseMsgError
{
public:
    CameraError(std::string filename,
                std::string classname,
                int numberline,
                const char *time,
                std::string info = "Camera was not add or set!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
};

class ObjectError: public BaseMsgError
{
public:
    ObjectError(std::string filename,
                std::string classname,
                int numberline,
                const char *time,
                std::string info = "Object was not found!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
};

class ModelError: public BaseMsgError
{
public:
    ModelError(std::string filename,
               std::string classname,
               int numberline,
               const char *time,
               std::string info = "Wrong number of model!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
};

class ModelOutRange: public BaseMsgError
{
public:
    ModelOutRange(std::string filename,
                  std::string classname,
                  int numberline,
                  const char *time,
                  std::string info = "Model is out of range"):
        BaseMsgError(filename, classname, numberline, time, info) {}
};

class MemoryError: public BaseMsgError
{
public:
    MemoryError(std::string filename,
                std::string classname,
                int numberline,
                const char *time,
                std::string info = "Memory error!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
};

class ZerodivError: public BaseMsgError
{
public:
    ZerodivError(std::string filename,
                 std::string classname,
                 int numberline,
                 const char *time,
                 std::string info = "Zero division error!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
};

class IndexError: public BaseMsgError
{
public:
    IndexError(std::string filename,
               std::string classname,
               int numberline,
               const char *time,
               std::string info = "Index out of range!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
};

class FileOpenError: public BaseMsgError
{
public:
    FileOpenError(std::string filename,
                  std::string classname,
                  int numberline,
                  const char *time,
                  std::string info = "Opening file error!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
};

class FileReadError: public BaseMsgError
{
public:
    FileReadError(std::string filename,
                  std::string classname,
                  int numberline,
                  const char *time,
                  std::string info = "Reading file error!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
};

class FileFormatError: public BaseMsgError
{
public:
    FileFormatError(std::string filename,
                    std::string classname,
                    int numberline,
                    const char *time,
                    std::string info = "Wrong format in file!"):
        BaseMsgError(filename, classname, numberline, time, info) {}
};


#endif // ERRORS_HPP
