#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <string>

 enum class ErrorCode { Success = 0, BadLengthExceptionErrorCode, UnknownErrorCode };

class BadLengthException : public std::runtime_error
{
public:
    BadLengthException(std::string const& err) : std::runtime_error(err)
    {}
};

int check_length(std::string str, int forbidden_length)
{
    std::string err;
    err += "Запретная длина строки: " + std::to_string(forbidden_length);
    err += "\nВаше слово: \"" + str +"\"";
    err += "\nДо свидания!";

    if (str.length() == forbidden_length) throw BadLengthException(err);
    return str.length();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите запретную длину строки: ";
    int zapret = 0;
    std::cin >> zapret;

    std::string current_str;
    int current_length = 0;

    do
    {
        std::cout << "Введите слово: ";
        std::cin >> current_str;

        try
        {
            current_length = check_length(current_str, zapret);
        }
        catch (const BadLengthException& ex)
        {
            std::cout << ex.what() << std::endl;
            return static_cast<int>(ErrorCode::BadLengthExceptionErrorCode);
        }
        catch (...)
        {
            std::cout << "Неизвестная ошибка" << std::endl;
            return static_cast<int>(ErrorCode::UnknownErrorCode);
        }

        std::cout << "Длина слова \"" << current_str << "\" равна " << current_length << std::endl;
    } while (true);

    return static_cast<int>(ErrorCode::Success);
}