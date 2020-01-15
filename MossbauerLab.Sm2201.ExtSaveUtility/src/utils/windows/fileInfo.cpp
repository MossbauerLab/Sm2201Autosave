#include "fileInfo.h"

void MossbauerLab::Utils::Windows::FileInfoHelper::getLastChangedFile(TCHAR* directory, TCHAR* searchPattern)
{
    TCHAR fullPath[MAX_PATH];
    _tcscpy(fullPath, directory);
    _tcscat(fullPath, searchPattern);
    std::vector<WIN32_FIND_DATA> files;
    WIN32_FIND_DATA searchData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    hFind = FindFirstFile(fullPath, &searchData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        // todo: umv: return empty result
    }

    do
    {
        files.push_back(searchData);
    }
    while (FindNextFile(hFind, &searchData) != NULL);
    FindClose(hFind);
    std::vector<WIN32_FIND_DATA>::iterator it;
    // todo: select latest file
    WIN32_FIND_DATA latestFileData = searchData;
    ULONGLONG latestDateTime = (((ULONGLONG) latestFileData.ftLastWriteTime.dwHighDateTime) << 32) + 
                                latestFileData.ftLastWriteTime.dwLowDateTime;
    for (it = files.begin(); it != files.end(); it++)
    {
        ULONGLONG checkingDateTime = (((ULONGLONG) (*it).ftLastWriteTime.dwHighDateTime) << 32) + 
                                      (*it).ftLastWriteTime.dwLowDateTime;
        if(latestDateTime < checkingDateTime)
        {
            latestFileData = (*it);
            latestDateTime = checkingDateTime;
        }
    }
    int a = 1;
}