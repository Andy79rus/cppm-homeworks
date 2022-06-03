#include "counter.h"

Counter::Counter()
	{
		setValue(1);
	}

Counter::Counter(int num)
	{
		setValue(num);
	}

int Counter::getValue()
	{
		return this->Value;
	}

void Counter::incValue()
	{
		setValue(getValue() + 1);
	}

void Counter::decValue()
	{
		setValue(getValue() - 1);
	}

void Counter::setValue(int num)
	{
		this->Value = num;
	}