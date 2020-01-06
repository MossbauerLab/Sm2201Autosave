#include "stdafx.h"
#include "Sm2201SaveManager.h"
#include <winbase.h>
#include <iostream>
#include <fstream>
#include <sstream>

DWORD WINAPI TimerThreadFunc (LPVOID lpParam) 
{ 
	MossbauerLab::Sm2201::Sm2201SaveManager* manager = (MossbauerLab::Sm2201::Sm2201SaveManager*)lpParam;
    if (manager == NULL)
	{
		std::cerr << "Thread function argument is NULL!" << std::endl;
		return -1;
	}

    int elapsedTime = 0;
    while(manager->IsThreadRunning())
	{
		// check after 1 sec, unfortunately we don't have here func like CreateWaitableTimer
		if(manager->GetState())
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


MossbauerLab::Sm2201::Sm2201SaveManager::Sm2201SaveManager(std::string& configFile)
    :_configFile(configFile), _threadRunning(true), _state(false)
{
	DWORD threadId;
    _timerThread = CreateThread(NULL, 0, TimerThreadFunc, this, 0, &threadId);
    
}

MossbauerLab::Sm2201::Sm2201SaveManager::~Sm2201SaveManager()
{
    _threadRunning = false;
	if (_timerThread != NULL)
		CloseHandle(_timerThread);
}

void MossbauerLab::Sm2201::Sm2201SaveManager::Start()
{
    // start timer
	_state = true;
}

void MossbauerLab::Sm2201::Sm2201SaveManager::Stop()
{
    // stop timer
	_state = false;
}

void MossbauerLab::Sm2201::Sm2201SaveManager::LoadConfig()
{
	char lineBuffer[512];
	std::ifstream configReader(_configFile.c_str());
	configReader.getline(lineBuffer, sizeof(lineBuffer)/sizeof(char));
	// todo: umv: trim 
	if(lineBuffer[0] != '#')
	{
	    // read configuration properties key=value
		std::string keyValuePair = lineBuffer;
        //if(lineBuffer.find("")
		//{
		//}
	}
	configReader.close();
}

