#include <iostream>
#include <cstdio>
#include <windows.h>

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

	bool operator==(Fraction other)
		{
			return this->numerator_ * other.denominator_ == this->denominator_ * other.numerator_;
		}

	bool operator!=(Fraction other)
		{
			return !(*this == other);
		}

	bool operator>(Fraction other)
		{
			return this->numerator_ * other.denominator_ > this->denominator_ * other.numerator_;
		}

	bool operator<(Fraction other)
		{
			return other > *this;
		}

	bool operator>=(Fraction other)
		{
			return !(*this < other);
		}

	bool operator<=(Fraction other)
		{
			return !(*this > other);
		}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Fraction f1;
	Fraction f2;

	try {
		f1.set_fraction(4, 3);
	}
	catch (const ZeroDenominatorException& ex)
	{
		std::cout << ex.what() << std::endl << "До свидания" << std::endl;
		return static_cast<int>(ErrorCode::ZeroDenominatorErrorCode);
	}
	catch(...)
	{
		std::cout << "Неизвестная ошибка" << std::endl;
		return static_cast<int>(ErrorCode::UnknownErrorCode);
	}

	try {
		f2.set_fraction(6, 11);
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

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	return static_cast<int>(ErrorCode::Success);;
}