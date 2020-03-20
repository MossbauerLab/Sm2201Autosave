#include <iostream>
#include <string.h>
#include "autoSaveManager.h"
#include "applicationTextUserInterface.h"

const std::string APP_STARTED_MSG = "started";
const std::string APP_STOPPED_MSG = "stopped";
const std::string UNKNOWN_CMD_MSG = "unknown";

/*****************************************************************
 * Алгоритм работы
 * 1. Запускаем приложение без аргументов
 * 2. Считываем конфигурацию ./autosaveConfig.txt
 * 3. Если хотя бы по одному каналу True, то
 * 3.1 Определяем окно, соответсвующее пронрамме MC.exe
 * 3.2 Включаем на него фокус ввода
 * 3.3 Отправляем события клавиатуры: последовательность для к.1
 *     и/или к.2
 *     Коды клавиш:
 *     W - сохранение спектра
 *     Right Arrow - переключение с канала 1 на канал 2
 *     Left Arrow - переключение с канала 2 на канал 1
 * 3.4 Копируем сохраненные .spc в архивную директорию
 * 3.5 Удаляем файлы из директории СМ2201
 *****************************************************************/
int main(int argc, char* argv[])
{
    MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::init();
    std::string condigFilePath = ".\\autosaveConfig.txt";
    std::string userInput;
    MossbauerLab::Sm2201::SaveManager::AutoSaveManager manager(condigFilePath);
    while(1)
    {
        std::cin >> userInput;
        if (strcmp(userInput.c_str(), "exit") == 0)
        {
            break;
        }
        if (strcmp(userInput.c_str(), "start") == 0)
        {  
            manager.start();
            MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::drawMsgStatus(APP_STARTED_MSG);
        }
        else if (strcmp(userInput.c_str(), "stop") == 0)
        {
            manager.stop();
            MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::drawMsgStatus(APP_STOPPED_MSG);
        }
        else 
        {
            if (userInput.size() > 1)
                MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::drawMsgStatus(UNKNOWN_CMD_MSG);
        }
        MossbauerLab::Sm2201::SaveManager::ApplicationTextUserInterface::clearCmd();
        userInput.erase(userInput.begin(), userInput.end());
    }
    return 0;
}



