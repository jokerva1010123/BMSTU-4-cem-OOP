#include "BaseException.h"

BaseException::BaseException(std::string fileName, std::string className, int currentLine,
                             const char *errorTime, std::string information = "Error")
{
    information = "\nFile: " + fileName + "\nCLass: " + className + "\nAt line: "+
            std::to_string(currentLine) + "\nIn time: " + errorTime +
            "About error: " + information;
}

const char *BaseException::what() const noexcept
{
    const char *result = information.c_str();
    return result;
}
