#include <windows.h>

namespace MossbauerLab
{
    namespace Utils
    {
        namespace Windows
        {
            class VxDAccessor
            {
            public:
                VxDAccessor();
                ~VxDAccessor();
                BYTE read(DWORD port);
                bool write(DWORD port, DWORD value);
            private:
                void init();
            private:
            };
        }
    }
}

