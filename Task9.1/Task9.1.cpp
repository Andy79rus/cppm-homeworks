#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	double FracToDecimal()
		{ 
			return static_cast<double>(numerator_) / denominator_;
		}

	bool operator==(Fraction other)
		{
			return FracToDecimal() == other.FracToDecimal();
		}

	bool operator!=(Fraction other)
		{
			return !(*this == other);
		}

	bool operator>(Fraction other)
		{
			return FracToDecimal() > other.FracToDecimal();
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
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}