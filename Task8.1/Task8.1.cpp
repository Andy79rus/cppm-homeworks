#include <iostream>
#include <Windows.h>
#include <cstdio>

enum class ErrorCode { Succses = 0, BadLengthExceptionErrorCode, UnknownErrorCode };

class BadLengthException : public std::exception
{
public:
    const char* what() const override { return "�� ����� ����� ��������� �����!"; }
};

int check_length(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length) throw BadLengthException();
    return str.length();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "������� ��������� ����� ������: ";
    int zapret = 0;
    std::cin >> zapret;

    std::string current_str;
    int current_length = 0;

    do
    {
        std::cout << "������� �����: ";
        std::cin >> current_str;

        try
        {
            current_length = check_length(current_str, zapret);
        }
        catch (const BadLengthException& ex)
        {
            std::cout << ex.what() << " �� ��������" << std::endl;
            return static_cast<int>(ErrorCode::BadLengthExceptionErrorCode);
        }
        catch (...)
        {
            std::cout << "����������� ������" << std::endl;
            return static_cast<int>(ErrorCode::UnknownErrorCode);
        }

        std::cout << "����� ����� \"" << current_str << "\" ����� " << current_length << std::endl;
    } while (true);

    return static_cast<int>(ErrorCode::Succses);
}