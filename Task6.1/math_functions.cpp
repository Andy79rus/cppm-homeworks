#include "math_functions.h"
#include <iostream>

void add(int a, int b)
{
	std::cout << a << " плюс " << b << " равно " << a+b << std::endl;
}

void subtract(int a, int b)
{
	std::cout << a << " минус " << b << " равно " << a-b << std::endl;
}

void multiply(int a, int b)
{
	std::cout << a << " умножить на " << b << " равно " << a*b << std::endl;
}

void divide(int a, int b)
{
	std::cout << a << " поделить на " << b << " равно " << static_cast<double>(a)/b << std::endl;
}

void powerof(int a, int b)
{
	int result = a;
	for (int i = 1; i < b; ++i)
		result *= a;
	std::cout << a << " в степени " << b << " равно " << result << std::endl;
}