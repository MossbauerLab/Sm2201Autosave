#ifndef SM2201_SPECTRUM_SAVER_SRC_UTILS_WINDOWS_FILE_INFO_H
#define SM2201_SPECTRUM_SAVER_SRC_UTILS_WINDOWS_FILE_INFO_H

#if WINVER < 0x0500
    #pragma warning(disable:4786)
#endif

#include <vector>
#include <string>
#include <windows.h>
#include <tchar.h>

namespace MossbauerLab
{
    namespace Utils
    {
        namespace Windows
        {
            class FileSearchResult;

            class FileInfoHelper
            {
            public:
                // directory MUST NOT ends with back clash, i.e. it MUST BE C:\\tmp
                static FileSearchResult* getLastChangedFile(const TCHAR* directory, const TCHAR* searchPattern);
                static TCHAR* getFileNameWithTimestamp(const TCHAR* file);
                static TCHAR* getFileNameWithoutExt(const TCHAR* file);
                static TCHAR* combinePath(const TCHAR* partOne, const TCHAR* partTwo);
            };

            class FileSearchResult
            {
            public:
                FileSearchResult(bool result, TCHAR* fileName, TCHAR* filePath);
                ~FileSearchResult();
                inline bool getResult() const {return _result;}
                inline const TCHAR* getFilePath() const {return const_cast<const TCHAR*>(_filePath);}
                inline const TCHAR* getFileName() const {return const_cast<const TCHAR*>(_fileName);}
            private:
                bool _result;
                TCHAR* _filePath;
                TCHAR* _fileName;
            };
        }
    }
}
#endif