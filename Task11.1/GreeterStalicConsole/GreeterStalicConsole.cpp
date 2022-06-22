#include <iostream>
#include "GreeterStaticLib.h"
#include <Windows.h>

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string name;
	if (argc > 1)
	{
		name = argv[1];
	}
	else
	{
		std::cout << "Введите имя: ";
		std::cin >> name;
	}

	GreeterStaticLib::Greeter TestClass;
	std::cout << TestClass.greet(name);

	return 0;
}