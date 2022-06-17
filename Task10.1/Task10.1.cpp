#include "Task10.1.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string name;
	if (1 == argc)
	{
		std::cout << "Введите имя: ";
		std::cin >> name;
	}
	else name = static_cast<std::string>(argv[1]);
	std::cout << "Здравствуйте, " << name << "!" << std::endl;

	return 0;
}