#include "vxdAccessor.h"
#include <winioctl.h>
#include <tchar.h>

#define IO32_WRITEPORT CTL_CODE(FILE_DEVICE_UNKNOWN, 1, METHOD_NEITHER, FILE_ANY_ACCESS)
#define IO32_READPORT CTL_CODE(FILE_DEVICE_UNKNOWN, 2, METHOD_NEITHER, FILE_ANY_ACCESS)

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
    DWORD result;
    DeviceIoControl(_hVxD, IO32_READPORT, &tagPort, sizeof(TagPort32), 
                    &portValue, sizeof(DWORD), &result, NULL);
    return portValue;
}

bool MossbauerLab::Utils::Windows::VxDAccessor::write(DWORD port, DWORD value, BYTE size)
{
    if (_hVxD == NULL)
        return false;
    DWORD result;
    MossbauerLab::Utils::Windows::TagPort32 tagPort;
    tagPort.bSize = size;
    tagPort.wPort = port;
    tagPort.dwValue = value;
    return DeviceIoControl(_hVxD, IO32_WRITEPORT, &tagPort, sizeof(tagPort), 
                           NULL, 0, &result, NULL);
}