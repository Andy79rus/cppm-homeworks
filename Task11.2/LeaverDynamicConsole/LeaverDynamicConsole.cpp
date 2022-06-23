#include "LeaverDynamicLib.h"
#include <iostream>
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
		std::cout << "¬ведите им€: ";
		std::cin >> name;
	}

	LeaverDynamicLib::Leaver TestClass;
	std::cout << TestClass.leave(name);

	return 0;
}