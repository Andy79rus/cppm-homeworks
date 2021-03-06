#include "Figure.h"
#include <iostream>

    // фигура(количество сторон = 0)
    void Figure::print_info(bool cr = true)
    {
        print_name();
        print_sides_count();
        std::cout << std::endl;
    }

    Figure::Figure(int n, const std::string& name = "Фигура")
    {
        set_sides_count(n);
        set_corners_count(n);
        set_name(name);
    }

    void Figure::print_sides_count()
    {
        std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
    }

    void Figure::print_name()
    {
        std::cout << this->get_name() << " ";
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