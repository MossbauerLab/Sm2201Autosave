#ifndef SM2201_SPECTRUM_SAVER_SRC_SAVE_MANAGER_AUTO_SAVE_MANAGER_H
#define SM2201_SPECTRUM_SAVER_SRC_SAVE_MANAGER_AUTO_SAVE_MANAGER_H

#include <string>
#include <windows.h>
#include "schedulerConfig.h"

namespace MossbauerLab
{
    namespace Sm2201
    {
        namespace SaveManager
        {
            class AutoSaveManager
            {
            public:
                AutoSaveManager(const std::string& configFile);
                ~AutoSaveManager();
                void start();
                void stop();
                inline bool getState() const {return _state;}
                inline bool isRunning() const {return _threadRunning;}
                inline MossbauerLab::Sm2201::Config::SchedulerConfig* getConfig() const {return _config;}
                void reloadConfig();
            private:
                MossbauerLab::Sm2201::Config::SchedulerConfig* _config;
                bool _state;
                bool _threadRunning;
                std::string _configFile;
                HANDLE _timerThread;
            };
        }
    }
}

#endif