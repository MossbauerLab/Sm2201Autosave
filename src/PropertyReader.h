#include <string>
#include <vector>

namespace MossbauerLab
{
    namespace Utils
	{
		class PropertiesReader
		{
		public:
			PropertiesReader(const std::string& fileName);
			std::string& getValue(const std::string& key) const;
			void reloadConfig();
		private:
			std::string _fileName;
			std::vector<std::string> _fileContent;
		}
	}
}