#include "fileInfo.h"

void MossbauerLab::Utils::Windows::FileInfoHelper::getLastChangedFile(TCHAR *directory, 
                                                                      TCHAR *fileSearchPattern)
{
    std::vector<WIN32_FIND_DATA> files;
    WIN32_FIND_DATA searchData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    hFind = FindFirstFile(directory, &searchData);
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
    // todo: umv: return result
}