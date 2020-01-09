#ifndef SM2201_SPECTRUM_SAVER_SRC_UTILS_STRING_BASE_UTILS_H
#define SM2201_SPECTRUM_SAVER_SRC_UTILS_STRING_BASE_UTILS_H

#include <string>

/* Utils for work with strings in application that are running on Windows 98
 * Because Win98 C++ stdlib don't have utilities for i.e. Trim
 */

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

                static long parseLong(const std::string& str, int radix = 10);
                static bool parseBool(const std::string& str);
            private:
                static int getDigit(char symbol);
            };
        }
    }
}
#endif