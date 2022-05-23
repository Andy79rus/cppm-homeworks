#include <iostream>
#include <windows.h>

class Calculator
{
	public:
		Calculator()
		{
			num1 = 0;
			num2 = 0;
		}

		double add()
		{
			return this->num1 + this->num2;
		}

		double multiply()
		{
			return this->num1 * this->num2;
		}

		double subtract_1_2()
		{
			return this->num1 - this->num2;
		}

		double subtract_2_1()
		{
			return this->num2 - this->num1;
		}

		double divide_1_2()
		{
			return this->num1 / this->num2;
		}

		double divide_2_1()
		{
			return this->num2 / this->num1;
		}

		bool set_num1(double num1)
		{
			if (0 == num1)
			{
				std::cout << "Неверный ввод!" << std::endl;
				return false;
			}

			this->num1 = num1;
			return true;
		}

		bool set_num2(double num2)
		{
			if (0 == num2)
			{
				std::cout << "Неверный ввод!" << std::endl;
				return false;
			}

			this->num2 = num2;
			return true;
		}

	private:
		double num1;
		double num2;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Calculator ACalc;

	double n1 = 0;
	double n2 = 0;

	while (true)
	{
		do
		{
			std::cout << "Введите num1: ";
			std::cin >> n1;
			if (std::cin.fail())
			{
				std::cin.clear();
			}
			std::cin.ignore(32767, '\n');
		} while (!(ACalc.set_num1(n1)));

		do
		{
			std::cout << "Введите num2: ";
			std::cin >> n2;
			if (std::cin.fail())
			{
				std::cin.clear();
			}
			std::cin.ignore(32767, '\n');
		} while (!(ACalc.set_num2(n2)));

		std::cout << "num1 + num2 = " << ACalc.add() << std::endl;
		std::cout << "num1 - num2 = " << ACalc.subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << ACalc.subtract_2_1() << std::endl;
		std::cout << "num1 * num2 = " << ACalc.multiply() << std::endl;
		std::cout << "num1 / num2 = " << ACalc.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << ACalc.divide_2_1() << std::endl;
	}

	return 0;
}