#include <iostream>

enum months
{
    january = 1,
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    october,
    november,
    december
};

void print_month(const months m)
{
    std::string month;

    switch (m)
    {
        case 1:
            month = "Январь";
            break;
        case 2:
            month = "Февраль";
            break;
        case 3:
            month = "Март";
            break;
        case 4:
            month = "Апрель";
            break;
        case 5:
            month = "Май";
            break;
        case 6:
            month = "Июнь";
            break;
        case 7:
            month = "Июль";
            break;
        case 8:
            month = "Август";
            break;
        case 9:
            month = "Сентябрь";
            break;
        case 10:
            month = "Октябрь";
            break;
        case 11:
            month = "Ноябрь";
            break;
        case 12:
            month = "Декабрь";
            break;
        default:
            month = "Неправильный номер!";
            break;
    }

    std::cout << month << std::endl;
}

int main()
{
    int month = 1;

    setlocale(LC_ALL, "Russian");
    
    do
    {
        std::cout << "Введите номер месяца: ";
        std::cin >> month;
        if (!(0 == month))
            {
                print_month(static_cast<months>(month));
            }
    } while (!(0 == month));

    std::cout << "До Свидания!";
    
    return 0;
}