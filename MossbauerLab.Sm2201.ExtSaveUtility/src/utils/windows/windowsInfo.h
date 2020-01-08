#ifndef SM2201_SPECTRUM_SAVER_SRC_UTILS_WINDOWS_WINDOWS_INFO_H
#define SM2201_SPECTRUM_SAVER_SRC_UTILS_WINDOWS_WINDOWS_INFO_H
#include <vector>
#include <string>
#include <windows.h>

namespace MossbauerLab
{
    namespace Utils
    {
        namespace Windows
        {
            struct WindowInfo
            {
                HWND hWnd;
                // std::wstring windowTitle;
                TCHAR windowTitle [512];
                DWORD processId; 
                //std::wstring processName;
                TCHAR processName [512];
            };

            class WindowInfoHelper
            {
            public:
                static std::vector<WindowInfo> get();
            };
        }
    }
}
#endif