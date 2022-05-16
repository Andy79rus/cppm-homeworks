#include <iostream>
#include <fstream>
#include <string>
#include <regex>

void shift_right(int* arr, int size)
{
	int tmp = arr[size - 1];
	for (int i = size-1; i > 0; --i)
		arr[i] = arr[i-1];
	arr[0] = tmp;
}

void shift_left(int* arr, int size)
{
	int tmp = arr[0];
	for (int i = 1; i < size; ++i)
		arr[i-1] = arr[i];
	arr[size-1] = tmp;
}

bool check_data_in_file(std::string file)
{
	std::ifstream file_to_use(file);
	std::string current_str;

	bool file_is_ok = true;

	if (!file_to_use.is_open())
		{
			std::cout << "Невозможно открыть файл. Файл не найден." << std::endl;
		}
	else
		{
			while (!file_to_use.eof())
				{
					file_to_use >> current_str;
					//Проверяем, что в символьной строке только цифры
					std::regex reg("^[0-9]{1,10}$");
					if (!(std::regex_match(current_str, reg)))
						{
							return false;
						}

				}
		}

	return file_is_ok;
}

int main()
{
	std::string filename1 = "in.txt";
	setlocale(LC_ALL, "Russian");

	if (check_data_in_file(filename1))
	{
		std::ifstream file_to_use(filename1);

		if (!file_to_use.is_open())
		{
			std::cout << "Невозможно открыть файл. Файл не найден." << std::endl;
		}
		else
		{
			std::string current_str;
			file_to_use >> current_str;
			int size1 = std::stoi(current_str);
			int* arr1 = new int[size1];
			for (int i = 0; i < size1; ++i)
			{
				file_to_use >> current_str;
				arr1[i] = std::stoi(current_str);
			}

			file_to_use >> current_str;
			int size2 = std::stoi(current_str);
			int* arr2 = new int[size2];
			for (int i = 0; i < size2; ++i)
			{
				file_to_use >> current_str;
				arr2[i] = std::stoi(current_str);
			}

			file_to_use.close();

			shift_right(arr2, size2);
			shift_left(arr1, size1);

			std::ofstream file_to_write("out.txt");

			file_to_write << size2 << std::endl;
			for (int i = 0; i < size2 - 1; ++i)
			{
				file_to_write << arr2[i] << " ";
			}
			file_to_write << arr2[size2 - 1] << std::endl;

			file_to_write << size1 << std::endl;
			for (int i = 0; i < size1 - 1; ++i)
			{
				file_to_write << arr1[i] << " ";
			}
			file_to_write << arr1[size1 - 1];

			file_to_write.close();

			delete[] arr1;
			delete[] arr2;
			arr1 = nullptr;
			arr2 = nullptr;
		}

	}
	else std::cout << "Неправильные данные в файле" << std::endl;

	return 0;
}
