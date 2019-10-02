#ifndef SM2201_SAVE_MANAGER_H
#define SM2201_SAVE_MANAGER_H

#include <string>
#include <windows.h>
#include "Sm2201saveScheduleConfig.h"

namespace MossbauerLab
{
    namespace Sm2201
	{
        class Sm2201SaveManager
		{
        public:
			Sm2201SaveManager(std::string& configFile);
			~Sm2201SaveManager();
			void Start();
			void Stop();
			inline bool GetState() {return _state;}
			inline bool IsThreadRunning() {return _threadRunning;}
        private:
			void LoadConfig();
		private:
			bool _state;
			bool _threadRunning;
			std::string _configFile;
			HANDLE _timerThread;
		};
	}
}

#endif