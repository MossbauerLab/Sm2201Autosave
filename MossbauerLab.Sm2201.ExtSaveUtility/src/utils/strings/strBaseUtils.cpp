#include "strBaseUtils.h"
#include <math.h>
#include <string.h>

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

int MossbauerLab::Utils::Strings::StrBaseUtils::indexOf(const TCHAR* str, const TCHAR* subStr)
{
    if (*str == NULL || *subStr == NULL)
        return -1;
    const TCHAR* scanningStr = subStr;
    bool matches = false;
    int index = 0;
    int matchIndex = 0;
    
    while(*str != NULL)
    {
        if(!matches)
        {
            if (*str == *scanningStr)
            {
                matches = true;
                scanningStr++;
                matchIndex = index;
            }
        }
        else
        {
            if (*scanningStr == NULL) // end of searching str, return index ...
            {
                return matchIndex;
            }

            if(*str != *scanningStr)
            {
                matches = false;
                scanningStr = subStr;
            }
            else
                scanningStr++;
        }
        str++;
        index++;
    }

    if (matches && *scanningStr == NULL)
        return matchIndex;
    return -1;
}

int MossbauerLab::Utils::Strings::StrBaseUtils::lastIndexOf(const TCHAR* str, const TCHAR* subStr)
{
    if (str == NULL || subStr == NULL)
        return -1;
    int searchIndex = 0;
    int subStrLen = _tcslen(subStr);
    const TCHAR* srcStr = str;
    int index = 0;
    int cycle = 0;
    bool anyMatch = false;

    while(index != -1)
    {
        index = indexOf(srcStr, subStr);
        if (index != -1)
        {
            searchIndex += index;
            srcStr += index + subStrLen;
            cycle++;
            anyMatch = true;
        }
    }

    if (!anyMatch)
        return -1;

    if (searchIndex > 0)
        searchIndex += subStrLen * (cycle - 1);
    return searchIndex;
}

long MossbauerLab::Utils::Strings::StrBaseUtils::parseLong(const std::string& str, int radix)
{
    long value = 0;
    int degree = 0;
    std::string::const_reverse_iterator rit;
    for (rit = str.rbegin(); rit != str.rend(); ++rit)
    {
        long multiplier = (long)pow((double)radix, (double)degree);
        char symbol = *rit;
        value += multiplier * getDigit(symbol);
        degree++;
    }
   
    return value;
}

bool MossbauerLab::Utils::Strings::StrBaseUtils::parseBool(const std::string& str)
{
    if (strcmp(str.c_str(), "0") == 0)
        return false;
    else if (strcmp(str.c_str(), "1") == 0)
        return true;
    else if (strcmp(str.c_str(), "false") == 0)
        return false;
    else if (strcmp(str.c_str(), "true") == 0)
        return true;
    return false;
}

int MossbauerLab::Utils::Strings::StrBaseUtils::getDigit(char symbol)
{
    int digit;
    if (symbol >= '0' && symbol <= '9')
    {
        digit = (int)symbol - 0x30;
        return digit;
    }
    switch(symbol)
    {
        case 'a':
        case 'A':
            return 10;
        case 'b':
        case 'B':
            return 11;
        case 'c':
        case 'C':
            return 12;
        case 'd':
        case 'D':
            return 13;
        case 'e':
        case 'E':
            return 14;
        case 'f':
        case 'F':
            return 15;
        default:
            return 0;
    }
}