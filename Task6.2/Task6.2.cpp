#include <iostream>
#include <windows.h>
#include "counter.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	std::string yesno;

	do
	{
		std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
		std::cin >> yesno;
		if (!(yesno == "да") && (!(yesno == "нет")))
			std::cout << "Неправильный ввод. Повторите." << std::endl;
	} while (!((yesno == "да") || (yesno == "нет")));

	int startnumber = 1;
	char command = '0';

	if (yesno == "да")
	{
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> startnumber;

		Counter Cntr(startnumber);

		do
		{
			std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
			std::cin >> command;
			if (command == '+')
				Cntr.incValue();
			else if (command == '-')
				Cntr.decValue();
			else if (command == '=')
				std::cout << Cntr.getValue() << std::endl;
			else if ((command != 'x') && (command != 'х'))
				std::cout << "Неверная комманда!" << std::endl;
		} while ((command != 'x') && (command != 'х'));
	}
	else // yesno == "нет"
	{
		Counter* Cntr = new Counter();

		std::cout << "Начальное значение счётчика (по умолчанию): " << Cntr->getValue() << std::endl;

		do
		{
			std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
			std::cin >> command;
			if (command == '+')
				Cntr->incValue();
			else if (command == '-')
				Cntr->decValue();
			else if (command == '=')
				std::cout << Cntr->getValue() << std::endl;
			else if ((command != 'x') && (command != 'х'))
				std::cout << "Неверная комманда!" << std::endl;
		} while ((command != 'x') && (command != 'х'));

		delete Cntr;
	}

	std::cout << "До свидания!" << std::endl;

	return 0;
}