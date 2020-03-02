#include "vxdAccessor.h"
#include <winioctl.h>
#include <tchar.h>

#define IO32_WRITEPORT 0x1001
#define IO32_READPORT  0x1000

MossbauerLab::Utils::Windows::VxDAccessor::VxDAccessor()
{
    bool initResult = init();
}

MossbauerLab::Utils::Windows::VxDAccessor::~VxDAccessor()
{
    if (_hVxD != NULL && _hVxD != INVALID_HANDLE_VALUE)
        CloseHandle(_hVxD);
}

bool MossbauerLab::Utils::Windows::VxDAccessor::init()
{
    _hVxD = CreateFile(_T("\\\\.\\DIO_W55"), 0, 0, 0, 
                       CREATE_NEW, FILE_FLAG_DELETE_ON_CLOSE, 0);
    DWORD errCode = GetLastError();
    return _hVxD != INVALID_HANDLE_VALUE;
}

DWORD MossbauerLab::Utils::Windows::VxDAccessor::read(DWORD port, BYTE size)
{
    if( _hVxD == NULL)
        return -1;
    MossbauerLab::Utils::Windows::TagPort32 tagPort;
    ZeroMemory(&tagPort, sizeof(tagPort));
    tagPort.bSize = size;
    tagPort.wPort = (unsigned short) port;
    DWORD portValue = 0;
    DWORD bytesRead = 0;
    bool readResult = DeviceIoControl(_hVxD, IO32_READPORT, &tagPort, sizeof(TagPort32), 
                                      &portValue, sizeof(DWORD), &bytesRead, NULL);
    DWORD errorCode = GetLastError();
    return portValue;
}

bool MossbauerLab::Utils::Windows::VxDAccessor::write(DWORD port, DWORD value, BYTE size)
{
    if (_hVxD == NULL)
        return false;
    DWORD result;
    MossbauerLab::Utils::Windows::TagPort32 tagPort;
    ZeroMemory(&tagPort, sizeof(tagPort));
    tagPort.bSize = size;
    tagPort.wPort = (unsigned short) port;
    tagPort.dwValue = value;
    bool writeResult = DeviceIoControl(_hVxD, IO32_WRITEPORT, &tagPort, sizeof(tagPort), 
                                       NULL, 0, &result, NULL);
    DWORD errorCode = GetLastError();
    return writeResult;
}