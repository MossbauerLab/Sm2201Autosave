#include "propertyReader.h"
#include "strBaseUtils.h"
#include <fstream>
#include <iostream>

const static std::string emptyProperty = "";

MossbauerLab::Utils::Config::PropertyReader::PropertyReader(const std::string &fileName)
    :_fileName(fileName)
{
    reload();
}

bool MossbauerLab::Utils::Config::PropertyReader::containsKey(const std::string &key) const
{
    return _properties.find(key) != _properties.end();
}

const std::string& MossbauerLab::Utils::Config::PropertyReader::get(const std::string &key) const
{
    if (!containsKey(key))
        return emptyProperty;
    std::map<std::string, std::string>::const_iterator it = _properties.find(key);
    return it->second;
}

void MossbauerLab::Utils::Config::PropertyReader::reload()
{
    std::ifstream propertyFileReader;
    propertyFileReader.open(_fileName.c_str(), std::ifstream::in);
    std::string line;
    while(propertyFileReader.good())
    {
        std::getline(propertyFileReader, line);
        int index = line.find("=");
        if (index > 0)
        {
            std::string key = line.substr(0, index);
            key = MossbauerLab::Utils::Strings::StrBaseUtils::trim(key.c_str(), key.length());
            if (key.empty() || key.at(0) == '#')
                continue;
            std::string value = line.length() - index >= 1 ? line.substr(index + 1, line.length() - (index + 1)) : "";
            if (value.length() >= 1)
                value = MossbauerLab::Utils::Strings::StrBaseUtils::trim(value.c_str(), value.length());
            _properties.insert(std::pair<std::string, std::string>(key, value));
        }
    }
    propertyFileReader.close();
}