#include <windows.h>

namespace MossbauerLab
{
    namespace Utils
    {
        namespace Windows
        {
            #pragma pack(1)
            struct tagPort32
            {
                USHORT wPort;
                ULONG dwValue;
                UCHAR bSize;
            };
            #pragma pack()

            class VxDAccessor
            {
            public:
                VxDAccessor();
                ~VxDAccessor();
                DWORD read(DWORD port, BYTE size = 1);
                bool write(DWORD port, DWORD value);
            private:
                bool init();
            private:
                HANDLE _hVxD;
            };
        }
    }
}

