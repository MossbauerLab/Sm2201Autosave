#ifndef SM2201_SPECTRUM_SAVER_SRC_CONFIG_SCHEDULER_CONFIG_H
#define SM2201_SPECTRUM_SAVER_SRC_CONFIG_SCHEDULER_CONFIG_H

#include <string>

namespace MossbauerLab
{
    namespace Sm2201
    {
        namespace Config
        {
            class SchedulerConfig
            {
            public:
                SchedulerConfig()(bool useChannelOne, bool useChannelTwo,
                                  int channelOnePeriod, int channelTwoPeriod, 
                                  std::string& outputeDir, std::string& archiveDir);
            private:
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