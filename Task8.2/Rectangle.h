#pragma once
#include "Quadrangle.h"

    // прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90)
    class Rectangle : public Quadrangle
    {
    public:
        Rectangle(int ac, int bd);

    protected:
        Rectangle(int ac, int bd, const std::string& name);
    };