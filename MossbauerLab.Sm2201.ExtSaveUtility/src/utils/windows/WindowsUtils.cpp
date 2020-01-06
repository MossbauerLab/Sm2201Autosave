#include "stdafx.h"
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include "WindowsUtils.h"

std::vector<WindowInfo> windowInfoList;

BOOL CALLBACK EnumWindowsCallback(HWND hWnd, LPARAM lparam)
{
	WindowInfo info;
	info.hWnd = hWnd;
	int length = GetWindowTextLength(hWnd);
	char* buffer = new char[length + 1];
	GetWindowText(hWnd, buffer, length + 1);
    info.windowTitle = buffer;
	delete[] buffer;
	GetWindowThreadProcessId(hWnd, &info.processId);
	// read process name:
	HANDLE procHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, info.processId);
		//OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, info.processId);
	if (procHandle != INVALID_HANDLE_VALUE)
	{
		char procPath[512];
		memset(procPath, 0, sizeof(procPath));
		if(GetModuleFileName((HMODULE)procHandle, procPath, sizeof(procPath) - 1))
		{
            info.processName = procPath;
		}
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
				   info.processName = procEntry.szExeFile;
				   //std::cout << "Proc name: " << procEntry.szExeFile << std::endl;
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

std::vector<WindowInfo>& GetWindowsInfo()
{
    windowInfoList.clear();
	EnumWindows(EnumWindowsCallback, NULL);
	return windowInfoList;
}