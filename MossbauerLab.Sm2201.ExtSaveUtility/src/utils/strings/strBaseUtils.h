#ifndef SM2201_SPECTRUM_SAVER_SRC_UTILS_STRING_BASE_UTILS_H
#define SM2201_SPECTRUM_SAVER_SRC_UTILS_STRING_BASE_UTILS_H

#if WINVER < 0x0500
    #pragma warning(disable:4786)
#endif

#include <string>
#include <windows.h>
#include <tchar.h>
/* Utils for work with strings in application that are running on Windows 98
 * Because Win98 C++ stdlib don't have utilities for i.e. Trim
 */

#ifndef TCHAR
    #define TCHAR unsigned char
#endif

namespace MossbauerLab
{
    namespace Utils
    {
        namespace Strings
        {
            class StrBaseUtils
            {
            public:
                static std::string ltrim(const char* str);
                static std::string rtrim(const char* str, int length);
                static std::string trim(const char* str, int length);
                static int indexOf(const TCHAR* str, TCHAR* subStr);
                static int lastIndexOf(const TCHAR* str, TCHAR* subStr);

                static long parseLong(const std::string& str, int radix = 10);
                static bool parseBool(const std::string& str);
            private:
                static int getDigit(char symbol);
            };
        }
    }
}
#endif