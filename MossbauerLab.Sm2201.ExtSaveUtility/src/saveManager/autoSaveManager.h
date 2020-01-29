#ifndef SM2201_SPECTRUM_SAVER_SRC_SAVE_MANAGER_AUTO_SAVE_MANAGER_H
#define SM2201_SPECTRUM_SAVER_SRC_SAVE_MANAGER_AUTO_SAVE_MANAGER_H

#pragma warning(disable:4786)
#pragma comment(linker, "/IGNORE:4786")

#include <string>
#include <vector>
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
                void sendKeysSequence(HWND window, int channel, int technology = 0);
            private:
                void sendKeysViaWindowMsg(HWND window, const std::vector<DWORD>& keys, int keyPause = 500);
                // HERE we send scancodes from group 1
                void sendKeysViaKeyboardController(const std::vector<BYTE>& scanCodes, int keyPause = 500);
                void sendKeysViaInput(const std::vector<DWORD>& keys, int keyPause = 500);
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