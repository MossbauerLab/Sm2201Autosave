#include <tchar.h>
#include "strBaseUtils.h"

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
                public ref class StrBaseUtilsTests
                {
                public: 

                    [TestMethod]
                    void TestParseLongDecRadix()
                    {
                        long result = MossbauerLab::Utils::Strings::StrBaseUtils::parseLong("1024", 10);
                        Assert::AreEqual(1024, result);
                        result = MossbauerLab::Utils::Strings::StrBaseUtils::parseLong("9047812", 10);
                        Assert::AreEqual(9047812, result);
                        result = MossbauerLab::Utils::Strings::StrBaseUtils::parseLong("10", 10);
                        Assert::AreEqual(10, result);
                        result = MossbauerLab::Utils::Strings::StrBaseUtils::parseLong("7", 10);
                        Assert::AreEqual(7, result);
                    };

                    [TestMethod]
                    void TestParseBool()
                    {
                        bool result = MossbauerLab::Utils::Strings::StrBaseUtils::parseBool("1");
                        Assert::AreEqual(true, result);
                        result = MossbauerLab::Utils::Strings::StrBaseUtils::parseBool("0");
                        Assert::AreEqual(false, result);
                        result = MossbauerLab::Utils::Strings::StrBaseUtils::parseBool("false");
                        Assert::AreEqual(false, result);
                        result = MossbauerLab::Utils::Strings::StrBaseUtils::parseBool("true");
                        Assert::AreEqual(true, result);
                    };

                    [TestMethod]
                    void TestIndexOf()
                    {
                        TCHAR str[30] = _T("C:\\Autosaves\\specs\\1S210620\\");
                        TCHAR pattern1[4] = _T("sav");
                        int index = MossbauerLab::Utils::Strings::StrBaseUtils::indexOf(str, pattern1);
                        Assert::AreEqual(7, index);
                        TCHAR pattern2[6] = _T("10620");
                        index = MossbauerLab::Utils::Strings::StrBaseUtils::indexOf(str, pattern2);
                        Assert::AreEqual(22, index);
                        TCHAR str2[22] = _T("C:\\Autosaves\\saved\\1");
                        TCHAR pattern3[6]=_T("saved");
                        index = MossbauerLab::Utils::Strings::StrBaseUtils::indexOf(str2, pattern3);
                        Assert::AreEqual(13, index);
                        TCHAR str3[4] = _T("api");
                        TCHAR pattern4[4] = _T("api");
                        index = MossbauerLab::Utils::Strings::StrBaseUtils::indexOf(str3, pattern4);
                        Assert::AreEqual(0, index);
                        TCHAR pattern5[5] = _T("apic");
                        index = MossbauerLab::Utils::Strings::StrBaseUtils::indexOf(str3, pattern5);
                        Assert::AreEqual(-1, index);
                    }

                    [TestMethod]
                    void TestLastIndexOf()
                    {
                        TCHAR str[16] = _T("C:\\apiapiapi");
                        TCHAR pattern1[4] = _T("api");
                        int index = MossbauerLab::Utils::Strings::StrBaseUtils::lastIndexOf(str, pattern1);
                        Assert::AreEqual(9, index);
                        TCHAR str2[28] = _T("C:\\Autosaves\\specs\\1S210620");
                        TCHAR pattern2[2] = _T("s");
                        index = MossbauerLab::Utils::Strings::StrBaseUtils::lastIndexOf(str2, pattern2);
                        Assert::AreEqual(17, index);
                        TCHAR pattern3[2] = _T("\\");
                        index = MossbauerLab::Utils::Strings::StrBaseUtils::lastIndexOf(str2, pattern3);
                        Assert::AreEqual(18, index);
                        TCHAR str3[29] = _T("C:\\Autosaves\\specs\\1S210620\\");
                        index = MossbauerLab::Utils::Strings::StrBaseUtils::lastIndexOf(str3, pattern3);
                        Assert::AreEqual(27, index);
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
