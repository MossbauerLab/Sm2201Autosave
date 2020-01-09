#include "strBaseUtils.h"

std::string MossbauerLab::Utils::Strings::StrBaseUtils::ltrim(const char *str)
{
    std::string resultStr;
    while(str != NULL)
    {
        if (*str != ' ' && *str != '\t')
            break;
        ++str;
    }
    resultStr.append(str);
    return resultStr;
}

std::string MossbauerLab::Utils::Strings::StrBaseUtils::rtrim(const char *str, int length)
{
    std::string resultStr;
    const char* strEnd = str + length - 1;  // because at length is \0 symbol
    int trimmedLen = length;
    if (length >= 1)
    {
        while (trimmedLen > 0)
        {
            if (*strEnd != ' ' && *strEnd != '\t')
                break;
            strEnd--;
            trimmedLen--;
        }
        resultStr.assign(str, str + trimmedLen);
    }
    return resultStr;
}

std::string MossbauerLab::Utils::Strings::StrBaseUtils::trim(const char *str, int length)
{
    std::string resultStr = ltrim(str);
    resultStr = rtrim(resultStr.c_str(), resultStr.length());
    return resultStr;
}

long MossbauerLab::Utils::Strings::StrBaseUtils::parseLong(const std::string& str, int radix)
{
    return -1;
}

bool MossbauerLab::Utils::Strings::StrBaseUtils::parseBool(const std::string& str)
{
    return false;
}