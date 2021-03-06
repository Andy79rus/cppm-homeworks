#include <iostream>
#include "Triangle.h"
#include "ErrorEx.h"
#include <sstream>

    // треугольник (стороны и углы произвольные, количество сторон = 3, сумма углов = 180)

    Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C, "Треугольник")
    {}

    Triangle::Triangle(int a, int b, int c, int A, int B, int C, const std::string& name) : Figure(tri, name)
    {
        set_sides_abc(a, b, c);
        set_corners_ABC(A, B, C);
        set_corners_count(tri);
        set_sides_count(tri);
        set_name(name);

        std::stringstream message;

        if ((a <= 0) || (b <= 0) || (c <= 0))
        {
            print_info(false);
            message.str(std::string());
            message << "Причина: ";
            message << "все длины сторон должны быть положительным числом";
            throw FigureException(message.str());
        }
        else if (((a + b) <= c) || ((b + c) <= a) || ((a + c) <= b))
        {
            print_info(false);
            message.str(std::string());
            message << "Причина: ";
            message << "сумма длин любых двух сторон треугольника должна быть строго больше длинны третьей стороны";
            throw FigureException(message.str());
        }
        else if (180 != (A + B + C))
        {
            print_info(false);
            message.str(std::string());
            message << "Причина: ";
            message << "сумма углов треугольника не равна 180";
            throw FigureException(message.str());
        }
    }

    void Triangle::print_info(bool cr)
    {
        print_name();
        print_sides();
        print_corners();
        if (cr) std::cout << " создан." << std::endl;
        else std::cout << " не создан." << std::endl;
    }

    void Triangle::print_sides()
    {
        std::cout << "(стороны ";
        for (int i = 0; i < this->get_sides_count()-1; ++i)
            std::cout << *(this->get_sides() + i) << ", ";
        std::cout << *(this->get_sides() + (this->get_sides_count() - 1)) << "; ";
    }

    void Triangle::print_corners()
    {
        std::cout << "углы ";
        for (int i = 0; i < this->get_corners_count()-1; ++i)
            std::cout << *(this->get_corners() + i) << ", ";
        std::cout << *(this->get_corners() + (this->get_corners_count() - 1)) << ")";
    }

    const int* Triangle::get_sides()
    {
        return this->side_abc;
    }

    const int* Triangle::get_corners()
    {
        return this->corner_ABC;
    }

    void Triangle::set_sides_abc(int a, int b, int c)
    {
        this->side_abc[0] = a;
        this->side_abc[1] = b;
        this->side_abc[2] = c;
    }

    void Triangle::set_corners_ABC(int A, int B, int C)
    {
        this->corner_ABC[0] = A;
        this->corner_ABC[1] = B;
        this->corner_ABC[2] = C;
    }