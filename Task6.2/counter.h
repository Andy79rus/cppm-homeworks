#pragma once
class Counter
{
public:
	Counter();
	Counter(int num);
	int getValue();
	void incValue();
	void decValue();

private:
	int Value;
	void setValue(int num);
};