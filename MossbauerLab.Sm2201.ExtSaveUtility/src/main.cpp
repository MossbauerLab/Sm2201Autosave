// Sm2201SpectrumSaver.cpp : Defines the entry point for the application.
//
#include <iostream>
//#include <iomanip.h>
#include <string.h>
#include "autoSaveManager.h"
//#include "windowsInfo.h"

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
    std::cout << " ===== >>> Spectrum saver is running <<< =====" << std::endl;
    std::string condigFilePath = ".\\autosaveConfig.txt";
    std::cout << " ===== >>> Type: start or stop or exit <<< =====" << std::endl;
    std::string userInput;
    MossbauerLab::Sm2201::SaveManager::AutoSaveManager manager(condigFilePath);
    while(1)
    {
        std::cin >> userInput;
        //std::cin.getline(userInput, 256);
        if (strcmp(userInput.c_str(), "exit") == 0)
        {
            break;
        }
        if (strcmp(userInput.c_str(), "start") == 0)
        {
            std::cout << " ===== >>> Autosave manager has been started. <<< =====" << std::endl;
            manager.start();
        }
        else if (strcmp(userInput.c_str(), "stop") == 0)
        {
            manager.stop();
            std::cout << " ===== >>> Autosave manager has been stopped. <<< =====" << std::endl;
        }
        else 
        {
            std::cout << " ===== >>> Unknown command <<< =====" << std::endl;
        }
        std::cout << " ===== >>> Type: start or stop or exit <<< =====" << std::endl;
    }
    std::cout << " ===== >>> Spectrum saver is stopping <<< =====" << std::endl;
    return 0;
}



