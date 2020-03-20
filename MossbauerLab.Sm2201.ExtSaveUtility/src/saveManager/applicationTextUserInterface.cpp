#include <ios>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
#include "applicationTextUserInterface.h"

HANDLE MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::_hConsole = 0;

void MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::init()
{
    _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::drawUi(bool autoSaveManagerState,
                                                                             const MossbauerLab::Sm2201::Config::SchedulerConfig* config,
                                                                             const MossbauerLab::Sm2201::SaveManager::AutoSaveStats* stats)
{
    CONSOLE_SCREEN_BUFFER_INFO consoleBuffer;
    BOOL result = GetConsoleScreenBufferInfo(_hConsole, &consoleBuffer);
    COORD consoleCoords;
    consoleCoords.X = 0;
    consoleCoords.Y = APP_TITLE;
    SetConsoleCursorPosition(_hConsole, consoleCoords);

    std::cout << APP_TITLE_STR << " |" << std:: endl;
    consoleCoords.X = 0;
    consoleCoords.Y = APP_TITLE + 1;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
    std::cout << std::setfill('-') << std::setw(strlen(APP_TITLE_STR) + 2) << "" << std::endl;

    consoleCoords.X = 0;
    consoleCoords.Y = APP_STATE - 1;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
    std::cout << std::setfill('-') << std::setw(strlen(APP_STATE_STR) + 4) << "" << std::endl;
    consoleCoords.X = 0;
    consoleCoords.Y = APP_STATE;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
    std::cout << APP_STATE_STR;
    showStatus(autoSaveManagerState);

    std::cout << "|" << std::endl;
    std::cout << std::setfill('-') << std::setw(strlen(APP_STATE_STR) + 4) << "" << std::endl;
    // ===================== > Application Channel 1
    consoleCoords.X = 0;
    consoleCoords.Y = CH1_STATE - 1;
    SetConsoleCursorPosition(_hConsole, consoleCoords);

    std::cout << std::setfill('-') << std::setw(60) << "";
    consoleCoords.X = 0;
    consoleCoords.Y = CH1_STATE;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
    clearLine(consoleBuffer, consoleCoords);
    std::cout << CHANNEL1_STATE_STR;

    showStatus(config->isChannelOneUsing());

    std::cout << "|" ;
    std::cout << TIME_LEFT_MESSAGE_STR;
    std::cout << std::right << std::setfill(' ') << std::setw(5)
              << stats->channel1TimeLeft << " sec " << "|";
    if (autoSaveManagerState && config->isChannelOneUsing())
    {
        std::cout << std::right << std::setfill(' ') << std::setw(25) 
                  << ctime(&stats->channel1SaveTime);
        //std::cout << "|";
    }

    // ===================== > Application Channel 2
    consoleCoords.X = 0;
    consoleCoords.Y = CH2_STATE;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
    clearLine(consoleBuffer, consoleCoords);
    std::cout << CHANNEL2_STATE_STR;
    showStatus(config->isChannelTwoUsing());

    std::cout << "|" ;
    std::cout << TIME_LEFT_MESSAGE_STR;
    std::cout << std::right << std::setfill(' ') << std::setw(5)
              << stats->channel2TimeLeft << " sec " << "|";
    if (autoSaveManagerState && config->isChannelTwoUsing())
    {
        std::cout << std::right << std::setfill(' ') << std::setw(25) 
                  << ctime(&stats->channel2SaveTime);
        //std::cout << "|";
    }

    consoleCoords.X = 0;
    consoleCoords.Y = CH2_STATE + 1;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
    std::cout << std::setfill('-') << std::setw(60) << "";
    // Application Cmd Line

    consoleCoords.X = 0;
    consoleCoords.Y = APP_CMD - 1;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
    std::cout << std::setfill('-') << std::setw(60) << "";
    
    consoleCoords.X = 0;
    consoleCoords.Y = APP_CMD + 1;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
    std::cout << std::setfill('-') << std::setw(60) << "";

    consoleCoords.X = 0;
    consoleCoords.Y = APP_CMD;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
    std::cout << APP_COMMAND_TITLE_STR << std::endl;

    consoleCoords.X = consoleBuffer.dwCursorPosition.X > 32 ? consoleBuffer.dwCursorPosition.X: 32;
    SetConsoleCursorPosition(_hConsole, consoleCoords);

}

void MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::drawMsgStatus(const std::string& msg)
{
    CONSOLE_SCREEN_BUFFER_INFO consoleBuffer;
    BOOL result = GetConsoleScreenBufferInfo(_hConsole, &consoleBuffer);
    COORD consoleCoords;

    consoleCoords.X = 0;
    consoleCoords.Y = APP_MSG_STATUS;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
    clearLine(consoleBuffer, consoleCoords);
    std::cout << APP_MSG_STATUS_STR << msg.c_str();
    consoleCoords.X = 0;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
}

void MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::clearCmd()
{
    CONSOLE_SCREEN_BUFFER_INFO consoleBuffer;
    BOOL result = GetConsoleScreenBufferInfo(_hConsole, &consoleBuffer);
    COORD consoleCoords;
    consoleCoords.X = 0;
    consoleCoords.Y = APP_CMD;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
    clearLine(consoleBuffer, consoleCoords);
    std::cout << APP_COMMAND_TITLE_STR << std::endl;
}

void MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::showStatus(bool status)
{
    bool colorApplyResult = true;
    if (status)
    {
        colorApplyResult = SetConsoleTextAttribute(_hConsole, 2);
        std::cout << std::left << std::setfill(' ') << std::setw(3) << "On";
    }
    else 
    {
        colorApplyResult = SetConsoleTextAttribute(_hConsole, 12);
        std::cout << std::left << std::setfill(' ') << std::setw(3) << "Off";
    }
    SetConsoleTextAttribute(_hConsole, 15);
}

void MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::clearLine(CONSOLE_SCREEN_BUFFER_INFO& buffer, COORD& consoleCoords)
{
    for (int c = 0; c < buffer.dwSize.X; c++)
    {
        std::cout << ' ';
    }
    consoleCoords.X = 0;
    SetConsoleCursorPosition(_hConsole, consoleCoords);
}