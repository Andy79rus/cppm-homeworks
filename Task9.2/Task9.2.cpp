#include <iostream>
#include <windows.h>

//ISO C++17 Standard (/std:c++17) to use std::gcd
#include <numeric>

enum class ErrorCode { Success = 0, ZeroDenominatorErrorCode, UnknownErrorCode };

class ZeroDenominatorException : public std::exception
{
public:
	const char* what() const override { return "Введен делитель равный 0!"; }
};

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction()
	{
		set_fraction(0, 1);
	}

	Fraction(int numerator, int denominator)
	{
		set_fraction(numerator, denominator);
	}

	void set_fraction(int numerator, int denominator)
	{
		if (0 == denominator) throw ZeroDenominatorException();
		else
		{
			numerator_ = numerator;
			denominator_ = denominator;
		}
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

	friend std::ostream& operator<<(std::ostream& os, const Fraction& a)
	{
		os << a.numerator_ << '/' << a.denominator_;
		return os;
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
	Fraction f1;

	try {
		f1.set_fraction(n1,d1);
	}
	catch (const ZeroDenominatorException& ex)
	{
		std::cout << ex.what() << std::endl << "До свидания" << std::endl;
		return static_cast<int>(ErrorCode::ZeroDenominatorErrorCode);
	}
	catch (...)
	{
		std::cout << "Неизвестная ошибка" << std::endl;
		return static_cast<int>(ErrorCode::UnknownErrorCode);
	}

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> n1;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> d1;
	Fraction f2;

	try {
		f2.set_fraction(n1, d1);
	}
	catch (const ZeroDenominatorException& ex)
	{
		std::cout << ex.what() << std::endl << "До свидания" << std::endl;
		return static_cast<int>(ErrorCode::ZeroDenominatorErrorCode);
	}
	catch (...)
	{
		std::cout << "Неизвестная ошибка" << std::endl;
		return static_cast<int>(ErrorCode::UnknownErrorCode);
	}

	std::cout << std::endl;

	std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << std::endl;
	std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << std::endl;
	std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << std::endl;
	std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << std::endl;

	std::cout << "-" << f1 << " = " << (-f1) << " Унарный минус" << std::endl;
	std::cout << "++" << f1 << " = " << (++f1) << " Новое значение 1: " << f1 << std::endl;
	std::cout << f1 << "++ = " << (f1++) << " Новое значение 1: " << f1 << std::endl;
	std::cout << "--" << f1 << " = " << (--f1) << " Новое значение 1: " << f1 << std::endl;
	std::cout << f1 << "-- = " << (f1--) << " Новое значение 1: " << f1 << std::endl;

	return static_cast<int>(ErrorCode::Success);
}