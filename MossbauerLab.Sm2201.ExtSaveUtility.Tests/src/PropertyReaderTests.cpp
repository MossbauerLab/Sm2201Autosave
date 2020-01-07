#include "propertyReader.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

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
                private:
					TestContext^ testContextInstance;

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
						std::string configWithoutComments = "..\\data\\configs\\configWithoutComments.txt";
						reader = new MossbauerLab::Utils::Config::PropertyReader(configWithoutComments);
						// todo: get each property and check ...
					};

					[TestMethod]
					void TestReadPropertiesWithCommentsAndWhiteSpaces()
					{
					};

                    [TestMethod]
					void TesttReadEmptyPropertyFile()
					{
					};

					[TestMethod]
					void TesttReadpropertiesThatAreNotProperties()
					{
					};

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
