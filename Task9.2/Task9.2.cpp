#include <iostream>
#include <windows.h>

//ISO C++17 Standard (/std:c++17) to use std::gcd
#include <numeric>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:

	Fraction()
	{
		numerator_ = 0;
		denominator_ = 1;
	}

	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	void reduce_fraction(Fraction& a)
	{
		int tmp = std::gcd(a.numerator_, a.denominator_);
		if (tmp > 1)
			{
				a.numerator_ /= tmp;
				a.denominator_ /= tmp;
			};
	}

	void print_fraction()
	{
		std::cout << numerator_ << "/" << denominator_;
	}

	Fraction operator+(const Fraction& other)
	{
		Fraction tmp;
		tmp.numerator_ = this->numerator_ * other.denominator_ + other.numerator_ * this->denominator_;
		tmp.denominator_ = this->denominator_ * other.denominator_;
		reduce_fraction(tmp);
		return tmp;
	}

	Fraction operator-(const Fraction& other)
	{
		Fraction tmp;
		tmp.numerator_ = this->numerator_ * other.denominator_ - other.numerator_ * this->denominator_;
		tmp.denominator_ = this->denominator_ * other.denominator_;
		reduce_fraction(tmp);
		return tmp;
	}

	Fraction operator*(const Fraction& other)
	{
		Fraction tmp;
		tmp.numerator_ = this->numerator_ * other.numerator_;
		tmp.denominator_ = this->denominator_ * other.denominator_;
		reduce_fraction(tmp);
		return tmp;
	}

	Fraction operator/(const Fraction& other)
	{
		Fraction tmp;
		tmp.numerator_ = this->numerator_ * other.denominator_;
		tmp.denominator_ = this->denominator_ * other.numerator_;
		reduce_fraction(tmp);
		return tmp;
	}

	Fraction operator-()
	{
		Fraction tmp;
		tmp.numerator_ = -(this->numerator_);
		tmp.denominator_ = this->denominator_;
		reduce_fraction(tmp);
		return tmp;
	}

	Fraction operator++()
	{
		this->numerator_ = this->numerator_ + this->denominator_;
		this->denominator_ = this->denominator_;
		reduce_fraction(*this);
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}

	Fraction operator--()
	{
		this->numerator_ = this->numerator_ - this->denominator_;
		this->denominator_ = this->denominator_;
		reduce_fraction(*this);
		return *this;
	}

	Fraction operator--(int)
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}
};

int main()
{
	int n1;
	int d1;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> n1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> d1;
	Fraction f1(n1, d1);

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> n1;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> d1;
	Fraction f2(n1, d1);
	std::cout << std::endl;

	f1.print_fraction();
	std::cout << " + ";
	f2.print_fraction();
	std::cout << " = ";
	(f1 + f2).print_fraction();
	std::cout << std::endl;

	f1.print_fraction();
	std::cout << " - ";
	f2.print_fraction();
	std::cout << " = ";
	(f1 - f2).print_fraction();
	std::cout << std::endl;

	f1.print_fraction();
	std::cout << " * ";
	f2.print_fraction();
	std::cout << " = ";
	(f1 * f2).print_fraction();
	std::cout << std::endl;

	f1.print_fraction();
	std::cout << " / ";
	f2.print_fraction();
	std::cout << " = ";
	(f1 / f2).print_fraction();
	std::cout << std::endl;

	std::cout << "-";
	f1.print_fraction();
	std::cout << " = ";
	(-f1).print_fraction();
	std::cout << " Унарный минус";
	std::cout << std::endl;

	std::cout << "++";
	f1.print_fraction();
	std::cout << " = ";
	(++f1).print_fraction();
	std::cout << " Новое значение 1: ";
	f1.print_fraction();
	std::cout << std::endl;

	f1.print_fraction();
	std::cout << "++";
	std::cout << " = ";
	(f1++).print_fraction();
	std::cout << " Новое значение 1: ";
	f1.print_fraction();
	std::cout << std::endl;

	std::cout << "--";
	f1.print_fraction();
	std::cout << " = ";
	(--f1).print_fraction();
	std::cout << " Новое значение 1: ";
	f1.print_fraction();
	std::cout << std::endl;

	f1.print_fraction();
	std::cout << "--";
	std::cout << " = ";
	(f1--).print_fraction();
	std::cout << " Новое значение 1: ";
	f1.print_fraction();
	std::cout << std::endl;

	return 0;
}