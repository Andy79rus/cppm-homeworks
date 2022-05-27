#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

class Address
{
	public:
		Address()
		{
			set_house(0);
			set_flat(0);
		}

		Address(std::string c, std::string s, int h, int f)
		{
			set_city(c);
			set_street(s);
			set_house(h);
			set_flat(f);
		}

		std::string print_address()
		{
			std::string result = "";
			result += this->City;
			result += ", ";
			result += this->Street;
			result += ", ";
			result += std::to_string(this->House);
			result += ", ";
			result += std::to_string(this->Flat);
			result += '\n';

			return result;
		}

		void set_city(std::string c)
		{
			this->City = c;
		}

		void set_street(std::string s)
		{
			this->Street = s;
		}

		void set_house(int h)
		{
			this->House = h;
		}

		void set_flat(int f)
		{
			this->Flat = f;
		}

	private:
		std::string City;
		std::string Street;
		int House;
		int Flat;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	std::string file_in = "in.txt";
	std::string file_out = "out.txt";

	std::ifstream file_to_read(file_in);

	if (!file_to_read.is_open())
	{
		std::cerr << "Невозможно открыть файл. Файл не найден." << std::endl;
		return 20;
	}

	std::string current_str;
	file_to_read >> current_str;
	int size1 = std::stoi(current_str);

	if (size1 <= 0)
	{
		std::cerr << "Неправильное количество адресов для обработки " << std::endl;
		return 21;
	}

	Address* arr1 = new Address[size1];

	for (int i = 0; i < size1; ++i)
	{
		file_to_read >> current_str;
		(arr1 + i)->set_city(current_str);
		file_to_read >> current_str;
		(arr1 + i)->set_street(current_str);
		file_to_read >> current_str;
		(arr1 + i)->set_house(stoi(current_str));
		file_to_read >> current_str;
		(arr1 + i)->set_flat(stoi(current_str));
	}

	file_to_read.close();

	std::ofstream file_to_write(file_out);

	file_to_write << size1 << std::endl;

	for (int i = size1 - 1; i >= 0; --i)
	{
		file_to_write << (arr1 + i)->print_address();
	}

	file_to_write.close();

	delete[] arr1;
	arr1 = nullptr;

	return 0;
}