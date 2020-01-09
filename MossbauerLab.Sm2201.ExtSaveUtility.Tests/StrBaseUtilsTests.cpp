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
