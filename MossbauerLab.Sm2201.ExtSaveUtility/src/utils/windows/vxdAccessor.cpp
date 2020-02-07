#include "vxdAccessor.h"
#include <winioctl.h>
#include <tchar.h>

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
    _hVxD = CreateFile(_T("\\\\.\\io32port.vxd"), 0, 0, NULL, 0, 
                       FILE_FLAG_DELETE_ON_CLOSE, NULL);

    return _hVxD != INVALID_HANDLE_VALUE;
}

DWORD MossbauerLab::Utils::Windows::VxDAccessor::read(DWORD port, BYTE size)
{
    if( _hVxD == NULL)
        return -1;
    MossbauerLab::Utils::Windows::TagPort32 tagPort;
    tagPort.bSize = size;
    tagPort.wPort = port;
    DWORD portValue = 0;
    DeviceIoControl(_hVxD, IO32_READPORT, &tagPort, sizeof(TagPort32), 
                    &portValue, sizeof(DWORD), NULL);
    return portValue;
}

bool MossbauerLab::Utils::Windows::VxDAccessor::write(DWORD port, DWORD value)
{
    return false;
}