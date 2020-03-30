#include "fileInfo.h"
#include <tchar.h>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace MossbauerLab
{
    namespace Sm2201
    {
        namespace ExtSaveUtility
        { 
            namespace Tests
            {
                [TestClass]
                public ref class FileInfoHelperTests
                {
                public: 

                    [TestMethod]
                    void TestGetLastSavedFile()
                    {
                        TCHAR outputDir[MAX_PATH] = _T("..\\..\\..\\MossbauerLab.Sm2201.ExtSaveutility.Tests\\data\\sm2201");
                        TCHAR searchPattern[MAX_PATH] = _T("\\*.spc");
                        MossbauerLab::Utils::Windows::FileSearchResult* result = MossbauerLab::Utils::Windows::FileInfoHelper::getLastChangedFile(outputDir, searchPattern);
                        Assert::AreEqual(true, result->getResult());
                        Assert::AreEqual(gcnew String(_T("spec2.spc")), gcnew String(result->getFileName()));
                    };

                    [TestMethod]
                    void TestGetTimestampedFileName()
                    {
                        TCHAR* fileName = _T("some_spec.spc");
                        TCHAR* timestampedFileName = MossbauerLab::Utils::Windows::FileInfoHelper::getFileNameWithTimestamp(fileName);
                        Assert::IsNotNull(gcnew String(timestampedFileName));
                        Assert::IsTrue(_tcslen(timestampedFileName) > _tcslen(fileName));
                    }

                    [TestMethod]
                    void TestGetTimestampedFileNameForFullPath()
                    {
                        TCHAR* fileName = _T("C:\\autosave\\some_spec.spc");
                        TCHAR* timestampedFileName = MossbauerLab::Utils::Windows::FileInfoHelper::getFileNameWithTimestamp(fileName);
                        Assert::IsNotNull(gcnew String(timestampedFileName));
                        Assert::IsTrue(_tcslen(timestampedFileName) > _tcslen(fileName));
                    }

                    [TestMethod]
                    void TestGetFileNameWithoutExtension()
                    {
                        TCHAR* fileName = _T("1S010220.spc");
                        TCHAR* fileNameWithoutExt = MossbauerLab::Utils::Windows::FileInfoHelper::getFileNameWithoutExt(fileName);
                        Assert::AreEqual(gcnew String(_T("1S010220")), gcnew String(fileNameWithoutExt));
                        fileName = _T("C:\\Autosaves\\specs\\1S010220.spc");
                        fileNameWithoutExt = MossbauerLab::Utils::Windows::FileInfoHelper::getFileNameWithoutExt(fileName);
                        Assert::AreEqual(gcnew String(_T("1S010220")), gcnew String(fileNameWithoutExt));
                        fileName = _T("1S010220");
                        fileNameWithoutExt = MossbauerLab::Utils::Windows::FileInfoHelper::getFileNameWithoutExt(fileName);
                        Assert::AreEqual(gcnew String(_T("1S010220")), gcnew String(fileNameWithoutExt));
                        fileName = _T("C:\\Autosaves\\specs\\1S010220");
                        fileNameWithoutExt = MossbauerLab::Utils::Windows::FileInfoHelper::getFileNameWithoutExt(fileName);
                        Assert::AreEqual(gcnew String(_T("1S010220")), gcnew String(fileNameWithoutExt));
                    }

                #pragma region InternalTestContext
                private:
                    TestContext^ testContextInstance;
                public:
                    /// <summary>
                    ///Gets or sets the test context which provides
                    ///information about and functionality for the current test run.
                    ///</summary>
                    property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
                    {
                        Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
                        {
                            return testContextInstance;
                        }
                        System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
                        {
                            testContextInstance = value;
                        }
                    };
                #pragma endregion
                };
            }
        }
    }
}
