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
                    void TestReadExistingScheduleConfig()
                    {
                        std::string configWithoutComments = "..\\..\\..\\MossbauerLab.Sm2201.ExtSaveUtility.Tests\\data\\configs\\autosaveConfig.txt";
                        config = new MossbauerLab::Sm2201::Config::SchedulerConfig(configWithoutComments);
                        Assert::AreEqual(true, config->getState());
                        Assert::AreEqual(true, config->isChannelOneUsing());
                        Assert::AreEqual(true, config->isChannelTwoUsing());
                        Assert::AreEqual(3600, config->getChannelOnePeriod());
                        Assert::AreEqual(7200, config->getChannelTwoPeriod());
                        Assert::AreEqual("C:\\SM2201\\Specs", gcnew String(config->getOutputDir().c_str()));
                        Assert::AreEqual("C:\\SavedSpecs", gcnew String(config->getArchiveDir().c_str()));
                    };

                    [TestMethod]
                    void TestReadTrimmedScheduleConfig()
                    {
                    }

                    [TestMethod]
                    void TestReadConfigOverwriteAndReload()
                    {
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
                    MossbauerLab::Sm2201::Config::SchedulerConfig* config;
                };
            }
        }
    }
}
