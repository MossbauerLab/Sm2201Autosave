#include "propertyReader.h"

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
                public ref class PropertyReaderTests
                {
                public: 
                    [TestInitialize()]
                    void SetUp()
                    {
                        reader = NULL;
                    }

                    [TestCleanup()]
                    void CleanUp() 
                    {
                        if (reader != NULL)
                            delete reader;
                    };
                    /// <summary>
                    /// In this tests we have file with different by type pair of properties without spaces
                    /// or comments, we attempt 
                    ///</summary>
                    [TestMethod]
                    void TestReadPropertiesWithoutCommentsAndSpaces()
                    {
                        System::String^ currentDir = System::IO::Path::GetFullPath(".");
                        System::Console::WriteLine("Current working directory is: " + currentDir);
                        std::string configWithoutComments = "..\\..\\..\\MossbauerLab.Sm2201.ExtSaveutility.Tests\\data\\configs\\configWithoutComments.txt";
                        reader = new MossbauerLab::Utils::Config::PropertyReader(configWithoutComments);
                        // checking existing keys
                        checkKeyAndValue("propertyInt", true, "110");
                        checkKeyAndValue("propertyFloat", true, "135.567");
                        checkKeyAndValue("propertyStr", true, "sample string (short)");
                        checkKeyAndValue("propertyStrPathWin", true, "C:\\Program Data\\SM2201\\AutoSaves");
                        checkKeyAndValue("propertyDateTime", true, "2020-01-14 16:01:52");
                        // checking non-existing keys
                        checkKeyAndValue("non-existing-prop", false, "");
                    };

                    [TestMethod]
                    void TestReadPropertiesWithCommentsAndWhiteSpaces()
                    {
                        std::string configWithoutComments = "..\\..\\..\\MossbauerLab.Sm2201.ExtSaveutility.Tests\\data\\configs\\configWithComments.txt";
                        reader = new MossbauerLab::Utils::Config::PropertyReader(configWithoutComments);
                        checkKeyAndValue("propertyInt", true, "110");
                        checkKeyAndValue("propertyFloat", true, "135.567");
                        checkKeyAndValue("propertyStr", true, "sample string (short)");
                        checkKeyAndValue("propertyStrPathWin", true, "C:\\Program Data\\SM2201\\AutoSaves");
                        checkKeyAndValue("propertyDateTime", true, "2020-01-14 16:01:52");
                    };

                    [TestMethod]
                    void TesttReadEmptyPropertyFile()
                    {
                    };

                    [TestMethod]
                    void TesttReadpropertiesThatAreNotProperties()
                    {
                    };
                private:
                    void checkKeyAndValue(std::string key, bool keyExists, std::string expectedValue)
                    {
                        bool keyCheck = reader->containsKey(key);
                        Assert::AreEqual(keyExists, keyCheck);
                        if (keyExists)
                            Assert::AreEqual<System::String^>(gcnew String(expectedValue.c_str()), 
                                                              gcnew String(reader->get(key).c_str()));
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

                private:
                    MossbauerLab::Utils::Config::PropertyReader* reader;
                    //std::string configWithoutComments = "..\\data\\configs\\configWithoutComments.txt";
                    //std::string configWithComments = "..\\data\\configs\\configWithComments.txt";
                    //std::string configWithNoContent = "..\\data\\configs\\emptyConfig.txt";
                    //std::string configWithNonPropertiesStr = "..\\data\\configs\\configWithNonPropertiesStr.txt";
                };
            }
        }
    }
}
