#pragma once
#include "Triangle.h"

namespace FigureHierarchy
{
    // прямоугольный треугольник (угол C всегда равен 90)
    class Right_Triangle : public Triangle
    {
    public:
        FIGUREHIERARCHY_API Right_Triangle(int a, int b, int c, int A, int B);

    private:
        bool check() override;
    };
}