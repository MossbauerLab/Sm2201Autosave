#ifndef SM2201_SPECTRUM_SAVER_SRC_SAVE_MANAGER_APPLICATION_TEXT_USER_INTERFACE_H
#define SM2201_SPECTRUM_SAVER_SRC_SAVE_MANAGER_APPLICATION_TEXT_USER_INTERFACE_H

#pragma warning(disable:4786)
#pragma comment(linker, "/IGNORE:4786")

#include <string>
#include <vector>
#include <windows.h>
#include <time.h>
#include "schedulerConfig.h"

namespace MossbauerLab
{
    namespace Sm2201
    {
        namespace SaveManager
        {
            enum UiLineNumber
            {
                APP_TITLE = 0,
                APP_STATE = 4,
                CH1_STATE = 7,
                CH2_STATE = 9,
                APP_CMD = 12,
                APP_MSG_STATUS = 14
            };

            #define APP_TITLE_STR "SM2201 Autosave manager utility"
            #define APP_COMMAND_TITLE_STR "Command (start, stop or exit): "
            #define APP_STATE_STR "STATE: "
            #define CHANNEL1_STATE_STR "CH 1: "
            #define CHANNEL2_STATE_STR "CH 2: "
            #define TIME_LEFT_MESSAGE_STR "Time left: "
            #define LAST_SAVE_MESSAGE_STR "Last save: "
            #define APP_MSG_STATUS_STR "Status: "

            struct AutoSaveStats
            {
                long channel1TimeLeft;
                long channel2TimeLeft;
                time_t channel1SaveTime;
                time_t channel2SaveTime;
                time_t channel1LastSaveTime;
                time_t channel2LastSaveTime;
                std::string status;
            };


            class ApplicationTextUserInterface
            {
            public:
                static void init();
                static void drawUi(bool autoSaveManagerState,
                                   const MossbauerLab::Sm2201::Config::SchedulerConfig* config,
                                   const MossbauerLab::Sm2201::SaveManager::AutoSaveStats* stats);
                static void clearCmd();
                static void drawMsgStatus(const std::string& msg);
            private:
                static void showStatus(bool status);
                static void clearLine(CONSOLE_SCREEN_BUFFER_INFO& buffer, COORD& consoleCoords);
            private:
                static HANDLE _hConsole;
            };

        }
    }
}

#endif