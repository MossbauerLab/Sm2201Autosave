#ifndef SM2201_SPECTRUM_SAVER_SRC_UTILS_WINDOWS_FILE_INFO_H
#define SM2201_SPECTRUM_SAVER_SRC_UTILS_WINDOWS_FILE_INFO_H
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
                // directory should not ends with back clash, i.e. C:\\tmp
                static FileSearchResult* getLastChangedFile(TCHAR* directory, TCHAR* searchPattern);
            };

            class FileSearchResult
            {
            public:
                FileSearchResult(bool result, TCHAR* filePath);
                ~FileSearchResult();
                inline bool getResult() const {return _result;}
                inline const TCHAR* getFilePath() const {return const_cast<const TCHAR*>(_filePath);}
            private:
                bool _result;
                TCHAR* _filePath;
            };
        }
    }
}
#endif