#include <iostream>
#include "Triangle.h"

// треугольник (стороны и углы произвольные, количество сторон = 3, сумма углов = 180)
Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure(tri)
    {
        set_sides_abc(a, b, c);
        set_corners_ABC(A, B, C);
        set_corners_count(tri);
        set_sides_count(tri);
        set_name("Треугольник");
    }

void Triangle::print_info()
    {
        print_name();
        print_check();
        print_sides_count();
        print_sides();
        print_corners();
        std::cout << std::endl;
    }

bool Triangle::check()
    {
        const int* s = this->get_sides();
        int s_count = this->get_sides_count();
        for (int i = 0; i < s_count; ++i)
        {
            if (*(s + i) <= 0) return false; // Проверяем, что длины сторон больше нуля.
        }
        // Cумма длин любых двух сторон должна быть строго больше длинны третей стороны.
        if ((*s >= *(s + 1) + *(s + 2)) || (*(s + 1) >= *s + *(s + 2)) || (*(s + 2) >= *s + *(s + 1))) return false;
        const int* c = this->get_corners();
        int c_count = this->get_sides_count();
        int corners_sum = 0;
        for (int i = 0; i < c_count; ++i)
        {
            corners_sum += *(c + i);
        }
        if (180 != corners_sum) return false; // Проверяем, что сумма углов фигуры равна 180.
        return true;
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