#include "autoSaveManager.h"
#include <winbase.h>
#include <iostream>
#include <fstream>
#include <sstream>

#define CHECK_INTERVAL 1000

DWORD WINAPI TimerThreadFunc (LPVOID lpParam) 
{ 
    MossbauerLab::Sm2201::SaveManager::AutoSaveManager* manager = (MossbauerLab::Sm2201::SaveManager::AutoSaveManager*)lpParam;
    if (manager == NULL)
    {
        std::cerr << "Thread function argument is NULL!" << std::endl;
        return -1;
    }

    long channellElapsedTime = 0;
    long channel2ElapsedTime = 0;

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
                        // todo: umv: impl save for channel 1
                    }
                    else
                    {
                        Sleep(CHECK_INTERVAL);
                        channellElapsedTime += CHECK_INTERVAL;
                    }
                }
                
                if (config->isChannelTwoUsing())
                {
                    if (channellElapsedTime >= config->getChannelTwoPeriod() * 1000)
                    {
                        // todo: umv: impl save for channel 1
                    }
                    else
                    {
                        Sleep(CHECK_INTERVAL);
                        channellElapsedTime += CHECK_INTERVAL;
                    }
                }
            }
            else
            {
                channellElapsedTime = 0;
                channel2ElapsedTime = 0;
                Sleep(CHECK_INTERVAL);
            }
            // todo: umv reload config
        }
        else
        {
            channellElapsedTime = 0;
            channel2ElapsedTime = 0;
            Sleep(CHECK_INTERVAL);
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

void MossbauerLab::Sm2201::SaveManager::AutoSaveManager::loadConfig()
{
    
}

