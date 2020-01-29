#include "autoSaveManager.h"
#include "windowsInfo.h"
#include "fileInfo.h"
#include <windows.h>
#include <winbase.h>
#include <winuser.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <tchar.h>
#include <conio.h>

#define CHECK_INTERVAL 1000
#define KEY_SEND_INTERVAL 1000
#define SM2201_UTILITY_TITLE _T("Untitled - Notepad")//_T("MC")//
                             
#define MSDOS_PROC_NAME _T("C:\\WINDOWS\\NOTEPAD.EXE")//_T("C:\\WINDOWS\\SYSTEM\\WINOA386.MOD")//
                        

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0401
#endif

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

    TCHAR outputDir[MAX_PATH];
    TCHAR fullOutputName [MAX_PATH];

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
                            // 1. Send Key Sequence
                            manager->sendKeysSequence(selectedWindows[0].hWnd, 1, 2);
                            // 2. Get last saved file from outputDir
                            #if WINVER > 0x0500
                                _stprintf_s(outputDir, sizeof(outputDir)/sizeof(TCHAR), _T("%hs"), config->getOutputDir().c_str());
                            #else
                                sprintf(outputDir, _T("%hs"), config->getOutputDir().c_str());
                            #endif
                            MossbauerLab::Utils::Windows::FileSearchResult* searchResult = MossbauerLab::Utils::Windows::FileInfoHelper::getLastChangedFile(outputDir, _T("\\*.spc"));
                            if (searchResult->getResult())
                            {
                                // 3. Copy to archiveDir
                                // 3.1 Getting timestamped filename
                                TCHAR* timestampedFileName = MossbauerLab::Utils::Windows::FileInfoHelper::getFileNameWithTimestamp(searchResult->getFileName());
                                // 3.2 Combine with autosaveDir
                                memset(fullOutputName, 0, MAX_PATH * sizeof(TCHAR));
                                _stprintf(fullOutputName, _T("%s%s"), config->getArchiveDir().c_str(), timestampedFileName);
                                // 3.3 Save
                                CopyFile(searchResult->getFilePath(), fullOutputName, false);
                                delete[] timestampedFileName;
                            }
                            //delete searchResult;
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
                            // 1. Send Key Sequence
                            manager->sendKeysSequence(selectedWindows[0].hWnd, 2, 2);
                            // 2. Get last saved file from outputDir
                            #if WINVER > 0x0500
                                _stprintf_s(outputDir, sizeof(outputDir)/sizeof(TCHAR), _T("%hs"), 
                                            config->getOutputDir().c_str());
                            #else
                                sprintf(outputDir, _T("%hs"), config->getOutputDir().c_str());
                            #endif
                            MossbauerLab::Utils::Windows::FileSearchResult* searchResult = MossbauerLab::Utils::Windows::FileInfoHelper::getLastChangedFile(outputDir, _T("\\*.spc"));
                            if (searchResult->getResult())
                            {
                                // 3. Copy to archiveDir
                                // 3.1 Getting timestamped filename
                                TCHAR* timestampedFileName = MossbauerLab::Utils::Windows::FileInfoHelper::getFileNameWithTimestamp(searchResult->getFileName());
                                // 3.2 Combine with autosaveDir
                                memset(fullOutputName, 0, MAX_PATH * sizeof(TCHAR));
                                _stprintf(fullOutputName, _T("%s\\%s"), config->getArchiveDir().c_str(), timestampedFileName);
                                // 3.3 Save
                                CopyFile(searchResult->getFilePath(), fullOutputName, false);
                                delete[] timestampedFileName;
                            }
                            // delete searchResult;
                            std::cout << "===== >>> Save spectrum from channel 2. <<< =====" << std::endl;
                        }           else if (numberOfWindows > 1)
             
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

void MossbauerLab::Sm2201::SaveManager::AutoSaveManager::sendKeysSequence(HWND window, int channel, int technology)
{
    // 0. make window active
    /*INPUT keyBoardInput;
    keyBoardInput.type = INPUT_KEYBOARD;
    keyBoardInput.ki.wScan = 0;
    keyBoardInput.ki.time = 0;
    keyBoardInput.ki.dwExtraInfo = 0;

    keyBoardInput.ki.wVk = VK_MENU;
    keyBoardInput.ki.dwFlags = 0;   // key down
    SendInput(1, &keyBoardInput, sizeof(INPUT));
    
    //SetForegroundWindow(window);
    keyBoardInput.ki.dwFlags = 2;   // key up
    SendInput(1, &keyBoardInput, sizeof(INPUT));*/

    std::vector<DWORD> charCodes;
    if (channel == 1)
        charCodes.push_back(VK_LEFT);
    else charCodes.push_back(VK_RIGHT);
    charCodes.push_back(0x43);      // continue
    charCodes.push_back(VK_RETURN); // scaling coeff
    charCodes.push_back(VK_RETURN); // stop update
    charCodes.push_back(0x57);      // write
    charCodes.push_back(VK_RETURN); // submit name
    charCodes.push_back(VK_RETURN); // submit overwrite

    if (technology == 0) //sending via Windows MSG
    {        
        sendKeysViaWindowMsg(window, charCodes);
    }
    else if (technology == 1)
    {
        sendKeysViaInput(charCodes);
    }
    else
    {
        //_outp(0x64, 0xAD);
        //Sleep(6000);
        int result;
        int status = _inp(0x64);
        std::cout <<"Keyboard status: "<< status << std::endl;
        while (status & 1)
            Sleep(10);
        _outp(0x64, 0xD2);
        _outp(0x60, 0xE0);
        result = _inp(0x60);
        std::cout <<"Keyboard command result: "<< result << std::endl;
        Sleep(10);
        _outp(0x64, 0xD2);
        _outp(0x60, 0x5A);
        result = _inp(0x60);
        std::cout <<"Keyboard command result: "<< result << std::endl;
        while (status & 2)
            Sleep(10);
        Sleep(10);
        _outp(0x64, 0xD2);
        _outp(0x60, 0xE0);
        result = _inp(0x60);
        std::cout <<"Keyboard command result: "<< result << std::endl;
        Sleep(10);
        _outp(0x64, 0xD2);
        _outp(0x60, 0xF0);
        result = _inp(0x60);
        std::cout <<"Keyboard command result: "<< result << std::endl;
        Sleep(10);
        _outp(0x64, 0xD2);
        _outp(0x60, 0x5A);
        result = _inp(0x60);
        std::cout <<"Keyboard command result: "<< result << std::endl;*/
    }

}

void MossbauerLab::Sm2201::SaveManager::AutoSaveManager::sendKeysViaWindowMsg(HWND window, const std::vector<DWORD>& keys, int keyPause)
{
    std::vector<DWORD>::const_iterator it;
    
    for(it = keys.begin(); it != keys.end(); it++)
    {
        PostMessage(window, WM_KEYDOWN, (LPARAM)(*it), (WPARAM)0);
        Sleep(keyPause);
        PostMessage(window, WM_KEYUP, (LPARAM)(*it), (WPARAM)0);
        Sleep(keyPause);
    }
}

void MossbauerLab::Sm2201::SaveManager::AutoSaveManager::sendKeysViaInput(const std::vector<DWORD>& keys, int keyPause)
{
    std::vector<DWORD>::const_iterator it;
    INPUT keyBoardInput;
    keyBoardInput.type = INPUT_KEYBOARD;
    keyBoardInput.ki.wScan = 0;
    keyBoardInput.ki.time = 0;
    keyBoardInput.ki.dwExtraInfo = 0;
    
    for(it = keys.begin(); it != keys.end(); it++)
    {
        keyBoardInput.ki.wVk = (*it);
        keyBoardInput.ki.dwFlags = 0;   // key down
        SendInput(1, &keyBoardInput, sizeof(INPUT));
        Sleep(keyPause);
        keyBoardInput.ki.dwFlags = 2;   // key up
        SendInput(1, &keyBoardInput, sizeof(INPUT));
        Sleep(keyPause);
    }
}

void MossbauerLab::Sm2201::SaveManager::AutoSaveManager::sendKeysViaKeyboardController(const std::vector<int>& scanCodes)
{

}