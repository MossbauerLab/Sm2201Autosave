#include "vxdAccessor.h"
#include <winioctl.h>

MossbauerLab::Utils::Windows::VxDAccessor::VxDAccessor()
{
    bool initResult = init();
}

MossbauerLab::Utils::Windows::VxDAccessor::~VxDAccessor()
{
    if (_hVxD != NULL)
        CloseHandle(_hVxD);
}

bool MossbauerLab::Utils::Windows::VxDAccessor::init()
{
    _hVxD = CreateFile("\\\\.\\io32port.vxd", 0, 0, NULL, 0, 
                       FILE_FLAG_DELETE_ON_CLOSE, NULL);
}

DWORD MossbauerLab::Utils::Windows::VxDAccessor::read(DWORD port, BYTE size)
{
    return 0;
}

bool MossbauerLab::Utils::Windows::VxDAccessor::write(DWORD port, DWORD value)
{
    return false;
}