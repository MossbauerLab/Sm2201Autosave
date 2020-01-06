#include <vector>
#include <string>
#include <windows.h>

typedef struct WindowInfo
{
	HWND hWnd;
	std::string windowTitle;
	DWORD processId; 
	std::string processName;
};

std::vector<WindowInfo>& GetWindowsInfo();
