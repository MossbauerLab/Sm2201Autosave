#include "fileInfo.h"

MossbauerLab::Utils::Windows::FileSearchResult::FileSearchResult(bool result, TCHAR* fileName, TCHAR* filePath)
    :_result(result)
{
    if (result && filePath != NULL && fileName != NULL)
    {
        int filePathLength = _tcslen(filePath) + 1;  // _tcslen count without terminsting \0 byte
        _filePath = new TCHAR[filePathLength * sizeof(TCHAR)];
        #if WINVER >= 0x0500
            _tcscpy_s(_filePath, filePathLength, filePath);
        #else
            _tcscpy(_filePath, filePath);
        #endif

        int fileNameLength = _tcslen(fileName) + 1;  // _tcslen count without terminsting \0 byte
        _fileName = new TCHAR[fileNameLength * sizeof(TCHAR)];
        #if WINVER >= 0x0500
            _tcscpy_s(_fileName, fileNameLength, fileName);
        #else
            _tcscpy(_fileName, fileName);
        #endif
    }
    else 
    {
        _filePath = NULL;
        _fileName = NULL;
    }
}

MossbauerLab::Utils::Windows::FileSearchResult::~FileSearchResult()
{
    if (_filePath != NULL)
    {
        delete[] _filePath;
    }

    if (_fileName != NULL)
    {
        delete[] _fileName;
    }
}

MossbauerLab::Utils::Windows::FileSearchResult* MossbauerLab::Utils::Windows::FileInfoHelper::getLastChangedFile(const TCHAR* directory, const TCHAR* searchPattern)
{
    TCHAR fullPath[MAX_PATH];
    #if WINVER >= 0x0500
        _tcscpy_s(fullPath, _tcslen(directory) + 1, directory);
        _tcscat_s(fullPath, MAX_PATH, searchPattern);
    #else
        _tcscpy(fullPath, directory);
        _tcscat(fullPath, searchPattern);
    #endif
    std::vector<WIN32_FIND_DATA> files;
    WIN32_FIND_DATA searchData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    hFind = FindFirstFile(fullPath, &searchData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        return new MossbauerLab::Utils::Windows::FileSearchResult(false, NULL, NULL);
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

    TCHAR resultFile[MAX_PATH];
    #if WINVER >= 0x0500
        _tcscpy_s(resultFile, MAX_PATH, directory);
        _tcscat_s(resultFile, MAX_PATH, _T("\\"));
        _tcscat_s(resultFile, MAX_PATH, latestFileData.cFileName);
    #else
        _tcscpy(resultFile, directory);
        _tcscat(resultFile, _T("\\"));
        _tcscat(resultFile, latestFileData.cFileName);
    #endif
    MossbauerLab::Utils::Windows::FileSearchResult* result = new MossbauerLab::Utils::Windows::FileSearchResult(true, latestFileData.cFileName, resultFile);
    return result;
}

TCHAR* MossbauerLab::Utils::Windows::FileInfoHelper::getFileNameWithTimestamp(const TCHAR* file)
{
    int length = _tcslen(file);
    int timestampedLength = length + 22;
    // file name would have following scheme: name_YYYY-MM-dd_HH-mm-ss.ext
    TCHAR* timestampedName = new TCHAR[timestampedLength]; // 20 - timestamp len, 1 - 0
    
    memset(timestampedName, 0, timestampedLength * sizeof(TCHAR));
    SYSTEMTIME timestamp = {0};
    GetLocalTime(&timestamp);
    int index = _tcscspn(file, _T("."));
    int extensionLength = length - index + 2;
    TCHAR* extensionBuffer = new TCHAR[extensionLength];
    memset(extensionBuffer, 0, (extensionLength) * sizeof(TCHAR));
    #if WINVER >= 0x0500
        _tcsncpy_s(timestampedName, timestampedLength, file, index);
        _tcsncpy_s(extensionBuffer, extensionLength, &file[index], extensionLength);
        _stprintf_s(timestampedName, timestampedLength, _T("%s_%04d-%02d-%02d_%02d-%02d-%02d%s"), 
                    timestampedName, timestamp.wYear, timestamp.wMonth, timestamp.wDay, 
                    timestamp.wHour, timestamp.wMinute, timestamp.wSecond, extensionBuffer);
    #else
        _tcsncpy(timestampedName, file, index);
        _tcsncpy(extensionBuffer, &file[index], extensionLength);
        _stprintf(timestampedName, _T("%s_%04d-%02d-%02d_%02d-%02d-%02d%s"), 
                  timestampedName, timestamp.wYear, timestamp.wMonth, timestamp.wDay, 
                  timestamp.wHour, timestamp.wMinute, timestamp.wSecond, extensionBuffer);
    #endif
    delete[] extensionBuffer;
    return timestampedName;
}

TCHAR* MossbauerLab::Utils::Windows::FileInfoHelper::getFileNameWithoutExt(const TCHAR* file)
{
    //_tcsrchr(file,_T("\\"));
    return NULL;
}