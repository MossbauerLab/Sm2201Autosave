#include "autoSaveManager.h"
#include "windowsInfo.h"
#include <winbase.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <tchar.h>

#define CHECK_INTERVAL 1000
#define KEY_SEND_INTERVAL 1000
#define SM2201_UTILITY_TITLE _T("MC")
#define MSDOS_PROC_NAME _T("C:\\WINDOWS\\SYSTEM\\WINOA386.MOD")

DWORD WINAPI TimerThreadFunc (LPVOID lpParam) 
{ 
    MossbauerLab::Sm2201::SaveManager::AutoSaveManager* manager = (MossbauerLab::Sm2201::SaveManager::AutoSaveManager*)lpParam;
    if (manager == NULL)
    {
        std::cerr << "===== >>> Thread function argument is NULL! <<< =====" << std::endl;
        return -1;
    }

    long channellElapsedTime = 0;
    long channel2ElapsedTime = 0;
    long elapsedTime = 0;

    while(manager->isRunning())
    {
        MossbauerLab::Sm2201::Config::SchedulerConfig* config = manager->getConfig();
        if(manager->getState())
        {
            if (config->getState())
            {
                if (config->isChannelOneUsing())
                {
                    if (channellElapsedTime >= config->getChannelOnePeriod() * 1000)
                    {
                        std::vector<MossbauerLab::Utils::Windows::WindowInfo> allWindows = MossbauerLab::Utils::Windows::WindowInfoHelper::get();
                        std::vector<MossbauerLab::Utils::Windows::WindowInfo> selectedWindows = MossbauerLab::Utils::Windows::WindowInfoHelper::find(allWindows, MSDOS_PROC_NAME, SM2201_UTILITY_TITLE);
                        int numberOfWindows = selectedWindows.size();
                        if(numberOfWindows == 1)
                        {
                            // Send Key Sequence
                            manager->sendKeysSequence(selectedWindows[0].hWnd, 1);
                            // todo: umv: 2. Get last saved file from outputDir
                            // todo: umv: 3. Copy to archiveDir
                            std::cout << "===== >>> Save spectrum from channel 1. <<< =====" << std::endl;
                        }
                        else if (numberOfWindows > 1)
                        {
                            std::cout << "===== >>> There are more then 1 MS-DOS Window related to SM2201 Utility (MC.exe), please close inactive windows. <<< =====" << std::endl;
                        }
                        else if (numberOfWindows == 0)
                        {
                            std::cout << "===== >>> There are no MS-DOS Window related to SM2201 Utility (MC.exe). <<< =====" << std::endl;
                        }

                        channellElapsedTime = 0;
                    }
                    else
                    {
                        Sleep(CHECK_INTERVAL);
                        channellElapsedTime += CHECK_INTERVAL;
                        elapsedTime += CHECK_INTERVAL;
                    }
                }
                
                if (config->isChannelTwoUsing())
                {
                    if (channel2ElapsedTime >= config->getChannelTwoPeriod() * 1000)
                    {
                        std::vector<MossbauerLab::Utils::Windows::WindowInfo> allWindows = MossbauerLab::Utils::Windows::WindowInfoHelper::get();
                        std::vector<MossbauerLab::Utils::Windows::WindowInfo> selectedWindows = MossbauerLab::Utils::Windows::WindowInfoHelper::find(allWindows, MSDOS_PROC_NAME, SM2201_UTILITY_TITLE);
                        int numberOfWindows = selectedWindows.size();
                        if(numberOfWindows == 1)
                        {
                            // Send Key Sequence
                            manager->sendKeysSequence(selectedWindows[0].hWnd, 2);
                            // todo: umv: 2. Get last saved file from outputDir
                            // todo: umv: 3. Copy to archiveDir
                            std::cout << "===== >>> Save spectrum from channel 2. <<< =====" << std::endl;
                        }
                        else if (numberOfWindows > 1)
                        {
                            std::cout << "===== >>> There are more then 1 MS-DOS Window related to SM2201 Utility (MC.exe), please close inactive windows. <<< =====" << std::endl;
                        }
                        else if (numberOfWindows == 0)
                        {
                            std::cout << "===== >>> There are no MS-DOS Window related to SM2201 Utility (MC.exe). <<< =====" << std::endl;
                        }

                        channel2ElapsedTime = 0;
                    }
                    else
                    {
                        Sleep(CHECK_INTERVAL);
                        channel2ElapsedTime += CHECK_INTERVAL;
                        elapsedTime += CHECK_INTERVAL;
                    }
                }
            }
            else
            {
                channellElapsedTime = 0;
                channel2ElapsedTime = 0;
                elapsedTime += CHECK_INTERVAL;
                Sleep(CHECK_INTERVAL);
            }
        }
        else
        {
            channellElapsedTime = 0;
            channel2ElapsedTime = 0;
            Sleep(CHECK_INTERVAL);
            elapsedTime += CHECK_INTERVAL;
        }
        
        if (elapsedTime > 0 && elapsedTime % (20 * CHECK_INTERVAL) == 0)
        {
            std::cout << "===== >>> Autosave manager config was reloaded. <<< =====" << std::endl;
            manager->reloadConfig();
            elapsedTime = 0;
        }
    }

    return 0; 
}


MossbauerLab::Sm2201::SaveManager::AutoSaveManager::AutoSaveManager(const std::string& configFile)
    :_configFile(configFile), _threadRunning(true), _state(false)
{
    _config = new MossbauerLab::Sm2201::Config::SchedulerConfig(_configFile);
    DWORD threadId;
    _timerThread = CreateThread(NULL, 0, TimerThreadFunc, this, 0, &threadId);
    
}

MossbauerLab::Sm2201::SaveManager::AutoSaveManager::~AutoSaveManager()
{
    _threadRunning = false;
    if (_timerThread != NULL)
        CloseHandle(_timerThread);
    delete _config;
}

void MossbauerLab::Sm2201::SaveManager::AutoSaveManager::start()
{
    // start timer
    _state = true;
}

void MossbauerLab::Sm2201::SaveManager::AutoSaveManager::stop()
{
    // stop timer
    _state = false;
}

void MossbauerLab::Sm2201::SaveManager::AutoSaveManager::reloadConfig()
{
    _config->reload();
}

void MossbauerLab::Sm2201::SaveManager::AutoSaveManager::sendKeysSequence(HWND window, int channel)
{
    // 1. Channel select
    if(channel == 1)
        SendMessage(window, WM_CHAR, (WPARAM)VK_LEFT, (LPARAM)0);
    else SendMessage(window, WM_CHAR, (WPARAM)VK_RIGHT, (LPARAM)0);
    Sleep (200);
    // 2. Update = Read from device
    SendMessage(window, WM_CHAR, (WPARAM)0x43, (LPARAM)0);       // C, continue
    Sleep (200);
    // 3. Enter scalling coefficient
    SendMessage(window, WM_CHAR, (WPARAM)VK_RETURN, (LPARAM)0);
    Sleep (200);
    // 4. Stop undate continiously
    SendMessage(window, WM_CHAR, (WPARAM)VK_RETURN, (LPARAM)0);
    Sleep (200);
    // 5. Write
    SendMessage(window, WM_CHAR, (WPARAM)0x57, (LPARAM)0);       // W, write
    Sleep (200);
    // 6. Enter - submit file name
    SendMessage(window, WM_CHAR, (WPARAM)VK_RETURN, (LPARAM)0);
    Sleep (200);
    // 7. Enter - overwrite file
    SendMessage(window, WM_CHAR, (WPARAM)VK_RETURN, (LPARAM)0);
    Sleep (200);
}