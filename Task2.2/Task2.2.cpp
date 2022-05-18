#include <iostream>
#include <windows.h>

struct Bank_account
{
    int account = 0;
    std::string name;
    float amount = 0;
};

void change_balance(Bank_account& ba)
{
    std::cout << "Введите новый баланс: ";
    std::cin >> ba.amount;
}

void print_account(const Bank_account& ba)
{
    std::cout << "Ваш счет: " << ba.name << ", " << ba.account << ", " << ba.amount << std::endl;
}

int main()
{
    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Bank_account person1;

    std::cout << "Введите номер счета: ";
    std::cin >> person1.account;
    std::cout << "Введите имя владельца:: ";
    std::cin >> person1.name;
    std::cout << "Введите баланс: ";
    std::cin >> person1.amount;

    change_balance(person1);

    print_account(person1);

    return 0;
}