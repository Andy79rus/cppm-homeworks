#include <iostream>
#include <windows.h>

struct full_adress
{
    std::string country;
    std::string city;
    std::string street;
    int house = 0;
    int flat = 0;
    int index = 0;
};

void print_adress1(const full_adress &fa)
{
    std::cout << "Страна: ";
    std::cout << fa.country;
    std::cout << std::endl;
    std::cout << "Город: ";
    std::cout << fa.city;
    std::cout << std::endl;
    std::cout << "Улица: ";
    std::cout << fa.street;
    std::cout << std::endl;
    std::cout << "Номер дома: ";
    std::cout << fa.house;
    std::cout << std::endl;
    std::cout << "Номер квартиры: ";
    std::cout << fa.flat;
    std::cout << std::endl;
    std::cout << "Индекс: ";
    std::cout << fa.index;
    std::cout << std::endl;
}

void print_adress2(const full_adress* fa)
{
    std::cout << "Страна: ";
    std::cout <<  (*fa).country;
    std::cout << std::endl;
    std::cout << "Город: ";
    std::cout << (*fa).city;
    std::cout << std::endl;
    std::cout << "Улица: ";
    std::cout << (*fa).street;
    std::cout << std::endl;
    std::cout << "Номер дома: ";
    std::cout << (*fa).house;
    std::cout << std::endl;
    std::cout << "Номер квартиры: ";
    std::cout << (*fa).flat;
    std::cout << std::endl;
    std::cout << "Индекс: ";
    std::cout << (*fa).index;
    std::cout << std::endl;
}

void print_adress3(const full_adress* fa)
{
    std::cout << "Страна: ";
    std::cout << fa->country;
    std::cout << std::endl;
    std::cout << "Город: ";
    std::cout << fa->city;
    std::cout << std::endl;
    std::cout << "Улица: ";
    std::cout << fa->street;
    std::cout << std::endl;
    std::cout << "Номер дома: ";
    std::cout << fa->house;
    std::cout << std::endl;
    std::cout << "Номер квартиры: ";
    std::cout << fa->flat;
    std::cout << std::endl;
    std::cout << "Индекс: ";
    std::cout << fa->index;
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    full_adress fa1;
    full_adress fa2;
    full_adress* fa3 = new full_adress;

    fa1.country = "Россия";
    fa1.city = "Калининград";
    fa1.street = "Малиновая";
    fa1.house = 22;
    fa1.flat = 7;
    fa1.index = 236023;

    fa2.country = "Россия";
    fa2.city = "Санкт-Петербург";
    fa2.street = "Причальная";
    fa2.house = 102;
    fa2.flat = 81;
    fa2.index = 197198;

    std::cout << "Введите страну: ";
    std::cin >> fa3->country;
    std::cout << "Введите город: ";
    std::cin >> fa3->city;
    std::cout << "Введите улицу: ";
    std::cin >> fa3->street;
    std::cout << "Введите номер дома: ";
    std::cin >> fa3->house;
    std::cout << "Введите номер квартиры: ";
    std::cin >> fa3->flat;
    std::cout << "Введите индекс: ";
    std::cin >> fa3->index;
    std::cout << std::endl;

    print_adress1(fa1);
    std::cout << std::endl;
    print_adress2(&fa2);
    std::cout << std::endl;
    print_adress3(fa3);

    delete fa3;

    return 0;
}