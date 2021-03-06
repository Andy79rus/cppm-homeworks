#pragma once
#include "Triangle.h"

namespace FigureHierarchy
{
    // равносторонний треугольник(все стороны равны, все углы равны 60)
    class Equilateral_Triangle : public Triangle
    {
    public:
        FIGUREHIERARCHY_API Equilateral_Triangle(int abc);

    private:
        bool check() override;
    };
}