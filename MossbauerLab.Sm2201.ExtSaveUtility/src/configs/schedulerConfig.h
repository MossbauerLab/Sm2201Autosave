#ifndef SM2201_SPECTRUM_SAVER_SRC_CONFIG_SCHEDULER_CONFIG_H
#define SM2201_SPECTRUM_SAVER_SRC_CONFIG_SCHEDULER_CONFIG_H

#pragma warning(disable:4786)
#pragma comment(linker, "/IGNORE:4786")

#include <string>
#include "propertyReader.h"

namespace MossbauerLab
{
    namespace Sm2201
    {
        namespace Config
        {
            class SchedulerConfig
            {
            public:
                SchedulerConfig(const std::string& schedulerConfigFile);
                ~SchedulerConfig();
                void reload();
                inline bool getState() const {return _state;}
                inline bool isChannelOneUsing() const {return _useChannelOne;}
                inline bool isChannelTwoUsing() const {return _useChannelTwo;}
                inline long getChannelOnePeriod() const {return _channelOnePeriod;}
                inline long getChannelTwoPeriod() const {return _channelTwoPeriod;}
                inline const std::string& getOutputDir() const {return _outputDir;}
                inline const std::string& getArchiveDir() const {return _archiveDir;}
            private:
                MossbauerLab::Utils::Config::PropertyReader* reader;
                bool _state;
                bool _useChannelOne;
                bool _useChannelTwo;
                long _channelOnePeriod;
                long _channelTwoPeriod;
                std::string _outputDir;
                std::string _archiveDir;
            };
        }
    }
}

#endif