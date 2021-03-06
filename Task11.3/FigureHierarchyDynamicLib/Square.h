#pragma once
#include "Rectangle.h"

namespace FigureHierarchy
{
    // квадрат (все стороны равны, все углы равны 90)
    class Square : public Rectangle
    {
    public:
        FIGUREHIERARCHY_API Square(int abcd);

    protected:
        bool check() override;
    };
}