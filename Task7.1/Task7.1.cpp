#include <iostream>
#include <windows.h>
#define MODE 1

#if (1 == MODE)
int add(int a, int b)
{
	return a + b;
}
#endif

int main()
{
	#ifndef MODE
	#error констатнта MODE не определена
	#endif // !MODE

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "ru_RU.UTF-8");

	#if (0 == MODE)
		std::cout << "Работаю в режиме тренировки" << std::endl;
	#elif (1 == MODE)
			std::cout << "Работаю в боевом режиме" << std::endl;
			int n1;
			int n2;
			std::cout << "Введите число 1: ";
			std::cin >> n1;
			std::cout << "Введите число 2: ";
			std::cin >> n2;
			std::cout << "Результат сложения: " << add(n1, n2) << std::endl;
	#elif std::cout << "Неизвестный режим. Завершение работы" << std::endl;
	#endif
	
	return 0;
}