#ifndef SM2201_SPECTRUM_SAVER_SRC_UTILS_WINDOWS_FILE_INFO_H
#define SM2201_SPECTRUM_SAVER_SRC_UTILS_WINDOWS_FILE_INFO_H
#include <vector>
#include <string>
#include <windows.h>
#include <tchar.h>

namespace MossbauerLab
{
    namespace Utils
    {
        namespace Windows
        {
            class FileInfoHelper
            {
            public:
                static void getLastChangedFile(TCHAR* searchPattern);
            };
        }
    }
}
#endif