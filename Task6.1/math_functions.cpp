#include "math_functions.h"
#include <iostream>

int add(int a, int b)
{
	return a+b;
}

int subtract(int a, int b)
{
	return  a-b;
}

int multiply(int a, int b)
{
	return a*b;
}

double divide(int a, int b)
{
	return static_cast<double>(a)/b;
}

int powerof(int a, int b)
{
	int result = a;
	for (int i = 1; i < b; ++i)
		result *= a;
	return result;
}