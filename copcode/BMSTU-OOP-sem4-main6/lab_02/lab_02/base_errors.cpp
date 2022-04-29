
#include "base_errors.h"

BaseMsgError::BaseMsgError(std::string filename,
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

const char *BaseMsgError::what() const noexcept
{
    return infoerror.c_str();
}

