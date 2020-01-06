#ifndef SM2201_SPECTRUM_SAVER_SRC_SAVE_MANAGER_AUTO_SAVE_MANAGER_H
#define SM2201_SPECTRUM_SAVER_SRC_SAVE_MANAGER_AUTO_SAVE_MANAGER_H

#include <string>
#include <windows.h>

namespace MossbauerLab
{
    namespace Sm2201
    {
        namespace SaveManager
        {
            class AutoSaveManager
            {
            public:
                AutoSaveManager(std::string& configFile);
                ~AutoSaveManager();
                void start();
                void stop();
                inline bool getState() {return _state;}
                inline bool isRunning() {return _threadRunning;}
            private:
                void loadConfig();
            private:
                bool _state;
                bool _threadRunning;
                std::string _configFile;
                HANDLE _timerThread;
            };
        }
    }
}

#endif