#ifndef SM2201_SPECTRUM_SAVER_SRC_UTILS_CONFIG_PROPERTY_READER_H
#define SM2201_SPECTRUM_SAVER_SRC_UTILS_CONFIG_PROPERTY_READER_H
#include <string>
#include <vector>

namespace MossbauerLab
{
    namespace Utils
    {
        namespace Config
        {
            class PropertyReader
            {
            public:
                PropertyReader(const std::string& fileName);
                const std::string& get(const std::string& key) const;
                void reload();
            private:
                std::string _fileName;
                std::vector<std::string> _fileContent;
            };
        }
    }
}
#endif