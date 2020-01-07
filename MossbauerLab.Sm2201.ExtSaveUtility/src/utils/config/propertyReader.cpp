#include "propertyReader.h"
#include <fstream>
#include <iostream>

MossbauerLab::Utils::Config::PropertyReader::PropertyReader(const std::string &fileName)
{
    std::ifstream propertyFileReader;
    propertyFileReader.open(fileName.c_str());
    // todo: get line ...
    propertyFileReader.close();
}

const std::string& MossbauerLab::Utils::Config::PropertyReader::get(const std::string &key) const
{
    std::string str;
    return str;
}

void MossbauerLab::Utils::Config::PropertyReader::reload()
{

}