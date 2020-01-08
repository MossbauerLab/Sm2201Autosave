#include "propertyReader.h"
#include <fstream>
#include <iostream>

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
        return "";
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
            std::string value = line.length() - index >= 1 ? line.substr(index + 1, line.length() - (index + 1)) : "";
            _properties.insert(std::pair<std::string, std::string>());
        }
    }
    propertyFileReader.close();
}