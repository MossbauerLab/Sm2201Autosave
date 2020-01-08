#include "windowsInfo.h"
#include <windows.h>
#include <tchar.h>
#include <tlhelp32.h>
#include <iostream>

// Windows 98 and Windows 2000 WINVER=0x0500

std::vector<MossbauerLab::Utils::Windows::WindowInfo> windowInfoList;
BOOL CALLBACK EnumWindowsCallback(HWND hWnd, LPARAM lparam);

std::vector<MossbauerLab::Utils::Windows::WindowInfo> MossbauerLab::Utils::Windows::WindowInfoHelper::get()
{
    windowInfoList.clear();
    EnumWindows(EnumWindowsCallback, NULL);
    return windowInfoList;
}

BOOL CALLBACK EnumWindowsCallback(HWND hWnd, LPARAM lparam)
{
    MossbauerLab::Utils::Windows::WindowInfo info;
    info.hWnd = hWnd;
    int length = GetWindowTextLength(hWnd);
    TCHAR* buffer = new TCHAR[length + 1];
    GetWindowText(hWnd, buffer, length + 1);
    // info.windowTitle = buffer;
    delete[] buffer;
    GetWindowThreadProcessId(hWnd, &info.processId);
    // read process name:
    HANDLE procHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, info.processId);
        //OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, info.processId);
    if (procHandle != INVALID_HANDLE_VALUE)
    {
        memset(info.processName, 0, sizeof(info.processName));
        GetModuleFileName((HMODULE)procHandle, info.processName, sizeof(info.processName));
        PROCESSENTRY32 procEntry;
        procEntry.dwSize = sizeof(PROCESSENTRY32);
        BOOL result = Process32First(procHandle, &procEntry);
        do
        {
            if(!result)
            {
                int error = GetLastError();
                std::cout << "Error code (Process32First): " << error << std::endl; 
            }
            else 
            {
                if(procEntry.th32ProcessID == info.processId)
                {
                    _tcscpy(info.processName, procEntry.szExeFile);
                   // std::cout << "Proc name: " << procEntry.szExeFile << std::endl;
                   break;
                }
                
            }
        }
        while(Process32Next(procHandle, &procEntry));
        
        CloseHandle(procHandle);
    }
    windowInfoList.push_back(info);
    return TRUE;
}