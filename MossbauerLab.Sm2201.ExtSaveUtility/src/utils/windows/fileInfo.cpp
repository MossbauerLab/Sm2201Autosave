#include "fileInfo.h"

MossbauerLab::Utils::Windows::FileSearchResult::FileSearchResult(bool result, TCHAR* filePath)
    :_result(result)
{
    if (result && filePath != NULL)
    {
        int length = _tcslen(filePath);
        _filePath = new TCHAR[length];
    }
}

MossbauerLab::Utils::Windows::FileSearchResult::~FileSearchResult()
{
    if (_filePath != NULL)
    {
        delete[] _filePath;
    }
}

MossbauerLab::Utils::Windows::FileSearchResult* MossbauerLab::Utils::Windows::FileInfoHelper::getLastChangedFile(TCHAR* directory, TCHAR* searchPattern)
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
        return new MossbauerLab::Utils::Windows::FileSearchResult(false, NULL);
    }

    do
    {
        if(!(searchData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
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
    return new MossbauerLab::Utils::Windows::FileSearchResult(true, NULL);
}