#ifndef SM2201_SAVE_SCHEDULE_CONFIG_H
#define SM2201_SAVE_SCHEDULE_CONFIG_H

#include <string>

namespace MossbauerLab
{
	namespace Sm2201
	{
        class Sm2201SaveScheduleConfig
		{
		public:
			Sm2201SaveScheduleConfig(){}
		    Sm2201SaveScheduleConfig(bool saveOnChannelOne, bool saveOnChannelTwo,
			                        int savePeriod, std::string& sm2201OutputDir, 
									std::string& archiveDir){}
		private:
            bool _saveOnChannelOne;
	        bool _saveOnChannelTwo;
	        int _savePeriod;
	        std::string _sm2201OutputDirectory;
	        std::string _archiveDirectory;
		};
	}
}

#endif