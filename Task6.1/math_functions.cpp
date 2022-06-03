#include "math_functions.h"
#include <iostream>

void add(int a, int b)
{
	std::cout << a << " ���� " << b << " ����� " << a+b << std::endl;
}

void subtract(int a, int b)
{
	std::cout << a << " ����� " << b << " ����� " << a-b << std::endl;
}

void multiply(int a, int b)
{
	std::cout << a << " �������� �� " << b << " ����� " << a*b << std::endl;
}

void divide(int a, int b)
{
	std::cout << a << " �������� �� " << b << " ����� " << static_cast<double>(a)/b << std::endl;
}

void powerof(int a, int b)
{
	int result = a;
	for (int i = 1; i < b; ++i)
		result *= a;
	std::cout << a << " � ������� " << b << " ����� " << result << std::endl;
}