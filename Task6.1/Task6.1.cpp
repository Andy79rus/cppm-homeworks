#include <iostream>
#include "math_functions.h"
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int n1 = 0;
	int n2 = 0;

	std::cout << "Введите первое число: ";
	std::cin >> n1;
	std::cout << "Введите второе число: ";
	std::cin >> n2;

	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	int answer;
	std::cin >> answer;
	switch (answer)
	{
		case 1: add(n1, n2);
			break;
		case 2: subtract(n1, n2);
			break;
		case 3: multiply(n1, n2);
			break;
		case 4: divide(n1, n2);
			break;
		case 5: powerof(n1, n2);
			break;
		default: 
			std::cout << "Неправильная операция" << std::endl;
			break;
	}
	
	return 0;
}