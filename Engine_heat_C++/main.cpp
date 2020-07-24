// Engine_heat_C++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "Stand.h"

int main()
{
	int ambientTemperature,time=0;
	setlocale(LC_ALL, "RUS");
	while (true)
	{
		system("cls");
		std::cout << "Введите температуру окружающей среды: " << std::endl;
		std::cin >> ambientTemperature;
		Engines::engine engine;
		TestStands::overHeatingTest<Engines::engine> stand(engine, ambientTemperature);
		time = stand.start();
		if (-1 == time)
		{
			std::cout << "Engine does not overheating. " << std::endl;
		}
		else {
			std::cout << "Engine overheating in: " << time << std::endl;
		}
		system("pause");
	}
	
}

