#ifndef SM2201_SPECTRUM_SAVER_SRC_UTILS_WINDOWS_VXD_ACCESSOR_H
#define SM2201_SPECTRUM_SAVER_SRC_UTILS_WINDOWS_VXD_ACCESSOR_H

#include <windows.h>

#if WINVER < 0x0500
    #pragma warning(disable:4786)
    #pragma comment(linker, "/IGNORE:4786")
#endif

namespace MossbauerLab
{
    namespace Utils
    {
        namespace Windows
        {
            #pragma pack(push, 1)
            struct TagPort32
            {
                USHORT wPort;
                ULONG dwValue;
                UCHAR bSize;
            };
            #pragma pack(pop)

            class VxDAccessor
            {
            public:
                VxDAccessor();
                ~VxDAccessor();
                DWORD read(DWORD port, BYTE size = 1);
                BOOL write(DWORD port, DWORD value, BYTE size = 1);
            private:
                bool init();
            private:
                HANDLE _hVxD;
            };
        }
    }
}

#endif
