#include "Rectangle.h"

// пр€моугольник (стороны a,c и b,d попарно равны, все углы равны 90)
Rectangle::Rectangle(int ac, int bd) : Quadrangle(ac, bd, ac, bd, 90, 90, 90, 90)
    {
        set_name("ѕр€моугольник");
    }

bool Rectangle::check()
    {
        if (!Quadrangle::check()) return false;
        // ѕравильность равенства противоположных сторон задаетс€ в конструкторе, в проверке нет необходимости.
        /*
            ‘ормально, провер€ть углы не надо, так как они задаютс€ в конструкторе Quadrangle равные 90
            const int* c = this->get_corners();
            int c_count = this->get_sides_count();
            for (int i = 0; i < c_count; ++i)
                {
                if (90 != *(c + i)) return false; // ѕровер€ем, что углы равны 90
                }
        */
        return true;
    }