#include "Rectangle.h"

    // прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90)
    Rectangle::Rectangle(int ac, int bd) : Rectangle::Rectangle(ac, bd, "Прямоугольник")
    {}

    Rectangle::Rectangle(int ac, int bd, const std::string& name) : Quadrangle(ac, bd, ac, bd, 90, 90, 90, 90, name)
    {}