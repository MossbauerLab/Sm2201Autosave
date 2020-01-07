#include "propertyReader.h"
#include <fstream>
#include <iostream>

MossbauerLab::Utils::Config::PropertyReader::PropertyReader(const std::string &fileName)
    :_fileName(fileName)
{
    reload();
}

const std::string& MossbauerLab::Utils::Config::PropertyReader::get(const std::string &key) const
{
    std::string str;
    return str;
}

void MossbauerLab::Utils::Config::PropertyReader::reload()
{
    std::ifstream propertyFileReader;
    propertyFileReader.open(_fileName.c_str(), std::ifstream::in);
    std::string line;
    while(propertyFileReader.good())
    {
        propertyFileReader >> line;
        int index = line.find("=");
        // todo: split
        if (index > 0)
        {
            std::string key = line.substr(0, index);
            std::string value = line.length() - index >= 1 ? line.substr(index + 1, line.length() - (index + 1)) : "";
            _properties.insert(std::pair<std::string, std::string>());
        }
    }
    propertyFileReader.close();
}