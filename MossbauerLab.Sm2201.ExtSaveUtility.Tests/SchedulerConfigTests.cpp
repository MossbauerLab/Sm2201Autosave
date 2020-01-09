#include "schedulerConfig.h"

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
                public ref class SchedulerConfigTests
                {
                public: 
                    [TestInitialize()]
                    void SetUp()
                    {
                        config = NULL;
                    }

                    [TestCleanup()]
                    void CleanUp() 
                    {
                        if (config != NULL)
                            delete config;
                    };

                    [TestMethod]
                    void TestReadPropertiesWithoutCommentsAndSpaces()
                    {
                        //System::String^ currentDir = System::IO::Path::GetFullPath(".");
                        //System::Console::WriteLine("Current working directory is: " + currentDir);
                        std::string configWithoutComments = "..\\..\\..\\MossbauerLab.Sm2201.ExtSaveutility.Tests\\data\\configs\\autosaveConfig.txt";
                        config = new MossbauerLab::Sm2201::Config::SchedulerConfig(configWithoutComments);
                        Assert::AreEqual(true, config->getState());
                        Assert::AreEqual(true, config->isChannelOneUsing());
                        Assert::AreEqual(true, config->isChannelTwoUsing());
                        
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

                private:
                    MossbauerLab::Sm2201::Config::SchedulerConfig* config;
                };
            }
        }
    }
}
