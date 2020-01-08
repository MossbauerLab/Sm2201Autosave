#include "autoSaveManager.h"
#include <winbase.h>
#include <iostream>
#include <fstream>
#include <sstream>

DWORD WINAPI TimerThreadFunc (LPVOID lpParam) 
{ 
    MossbauerLab::Sm2201::SaveManager::AutoSaveManager* manager = (MossbauerLab::Sm2201::SaveManager::AutoSaveManager*)lpParam;
    if (manager == NULL)
    {
        std::cerr << "Thread function argument is NULL!" << std::endl;
        return -1;
    }

    int elapsedTime = 0;
    while(manager->isRunning())
    {
        // check after 1 sec, unfortunately we don't have here func like CreateWaitableTimer
        if(manager->getState())
        {
            // get time 
            // elapsed += portion ...
        }
        else
        {
            Sleep(1000);
        }
        
    }

    return 0; 
}


MossbauerLab::Sm2201::SaveManager::AutoSaveManager::AutoSaveManager(std::string& configFile)
    :_configFile(configFile), _threadRunning(true), _state(false)
{
    DWORD threadId;
    _timerThread = CreateThread(NULL, 0, TimerThreadFunc, this, 0, &threadId);
    
}

MossbauerLab::Sm2201::SaveManager::AutoSaveManager::~AutoSaveManager()
{
    _threadRunning = false;
    if (_timerThread != NULL)
        CloseHandle(_timerThread);
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

