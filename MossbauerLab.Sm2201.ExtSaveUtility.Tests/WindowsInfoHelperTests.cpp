#include "windowsInfo.h"
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
                public ref class WindowsInfoHelperTests
                {
                public: 

                    [TestMethod]
                    void TestGetAllWindowsInfo()
                    {
                        std::vector<MossbauerLab::Utils::Windows::WindowInfo> allWindows = MossbauerLab::Utils::Windows::WindowInfoHelper::get();
                        int numberOfWindows = allWindows.size();
                        Assert::IsTrue(numberOfWindows > 0);
                    };

                    [TestMethod]
                    void TestGetWindowInfoByTitleAndProcess()
                    {
                        std::vector<MossbauerLab::Utils::Windows::WindowInfo> allWindows = MossbauerLab::Utils::Windows::WindowInfoHelper::get();
                        std::vector<MossbauerLab::Utils::Windows::WindowInfo> selectedWindows = MossbauerLab::Utils::Windows::WindowInfoHelper::find(allWindows, _T("devenv.exe"), _T("&Build"));
                        int numberOfWindows = selectedWindows.size();
                        Assert::IsTrue(numberOfWindows > 0);
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
