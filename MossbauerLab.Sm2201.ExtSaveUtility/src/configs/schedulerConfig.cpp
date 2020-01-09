#include "schedulerConfig.h"

static std::string stateKey = "state";               // 0 - OFF, 1 - ON
static std::string useChannelOneKey = "useChannel1"; // 0 - DO NOT SAVE ON CH1, 1 - SAVE ON CH 1
static std::string useChannelTwoKey = "useChannel2"; // 0 - DO NOT SAVE ON CH2, 1 - SAVE ON CH 2
static std::string channelOnePeriodKey = "channel1Period"; // SAVE PERION ON CH1 IN SECS, 1 - xxxx
static std::string channelTwoPeriodKey = "channel2Period"; // SAVE PERION ON CH2 IN SECS, 1 - xxxx
static std::string outputDirKey = "outputDir"; // Directory where SM2201 saves spectra
static std::string archiveDirKey = "archiveDir"; // Directory where we should save spectra from outputDir

MossbauerLab::Sm2201::Config::SchedulerConfig::SchedulerConfig(const std::string& schedulerConfigFile)
{
    reader = new MossbauerLab::Utils::Config::PropertyReader(schedulerConfigFile);
    reload();
}

MossbauerLab::Sm2201::Config::SchedulerConfig::~SchedulerConfig()
{
    delete reader;
}

void MossbauerLab::Sm2201::Config::SchedulerConfig::reload()
{
    reader->reload();
    std::string value = reader->get(stateKey);

    _outputDir = reader->get(outputDirKey);
    _archiveDir = reader->get(archiveDirKey);
}