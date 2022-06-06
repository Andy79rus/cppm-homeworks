#include "Rectangle.h"

// прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90)
Rectangle::Rectangle(int ac, int bd) : Quadrangle(ac, bd, ac, bd, 90, 90, 90, 90)
    {
        set_name("Прямоугольник");
    }

bool Rectangle::check()
    {
        if (!Quadrangle::check()) return false;
        // Правильность равенства противоположных сторон задается в конструкторе, в проверке нет необходимости.
        /*
            Формально, проверять углы не надо, так как они задаются в конструкторе Quadrangle равные 90
            const int* c = this->get_corners();
            int c_count = this->get_sides_count();
            for (int i = 0; i < c_count; ++i)
                {
                if (90 != *(c + i)) return false; // Проверяем, что углы равны 90
                }
        */
        return true;
    }