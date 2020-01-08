#include "strBaseUtils.h"

std::string MossbauerLab::Utils::Strings::StrBaseUtils::ltrim(const char *str)
{
    std::string resultStr;
    while(str != NULL)
    {
        if (*str != ' ')
            break;
        ++str;
    }
    resultStr.append(str);
    return resultStr;
}

std::string MossbauerLab::Utils::Strings::StrBaseUtils::rtrim(const char *str, int length)
{
    std::string resultStr;
    const char* strEnd = str + length;
    return resultStr;
}

std::string MossbauerLab::Utils::Strings::StrBaseUtils::trim(const char *str, int length)
{
    std::string resultStr = ltrim(str);
    return resultStr;
}