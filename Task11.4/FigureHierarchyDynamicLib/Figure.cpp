#include "Figure.h"
#include <iostream>

namespace FigureHierarchy
{
    // фигура(количество сторон = 0)
    Figure::Figure() : Figure(0)
    {}

    void Figure::print_info()
    {
        print_name();
        print_check();
        print_sides_count();
        std::cout << std::endl;
    }

    Figure::Figure(int n)
    {
        set_sides_count(n);
        set_corners_count(n);
        set_name("Фигура");
    }

    bool Figure::check()
    {
        return true; // базовая фигура правильная по-умолчанию
    }

    void Figure::print_check()
    {
        std::string status;
        (this->check()) ? status = "Правильная" : status = "Неправильная";
        std::cout << status << std::endl;
    }

    void Figure::print_sides_count()
    {
        std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
    }

    void Figure::print_name()
    {
        std::cout << this->get_name() << ":" << std::endl;
    }

    void Figure::set_sides_count(int n)
    {
        this->sides = n;
    }

    int Figure::get_sides_count()
    {
        return this->sides;
    }

    void Figure::set_corners_count(int n)
    {
        this->corners = n;
    }

    int Figure::get_corners_count()
    {
        return this->corners;
    }

    void Figure::set_name(std::string s)
    {
        this->name = s;
    }

    std::string Figure::get_name()
    {
        return this->name;
    }
}