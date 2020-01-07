// Sm2201SpectrumSaver.cpp : Defines the entry point for the application.
//

//#include "stdafx.h"
//#include "Sm2201SaveManager.h"
//#include "WindowsUtils.h"
#include <iostream>
//#include <iomanip.h>

/*****************************************************************
 * Алгоритм работы
 * 1. Запускаем приложение без аргументов
 * 2. Считываем конфигурацию ./sm2201SaveConfig.cfg
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
	/*char userInput[256];
	std::vector<WindowInfo> infoList = GetWindowsInfo();
    for(int i = 0; i < infoList.size(); i++)
	{
		WindowInfo info = infoList[i];
		if(info.windowTitle.size() > 0){
			int exeSearch = info.windowTitle.find("MC");
			if (exeSearch != std::string::npos)
		        std::cout << info.processName.c_str()<< ": " << info.windowTitle.c_str() << std::endl;

		}
	}
	std::cin.getline(userInput, 256);
	std::string condigFilePath = ".\\sm2201AutosaveConfig.cfg";
	MossbauerLab::Sm2201::Sm2201SaveManager manager(condigFilePath);
	manager.Start();
	manager.Stop();*/
	std::cout << " ===== >>> Spectrum saver is stopping <<< =====" << std::endl;
	return 0;
}



