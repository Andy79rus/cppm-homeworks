#pragma once
#include "Triangle.h"

#ifdef FIGUREHIERARCHYLIBRARYDYNAMIC_EXPORTS
#define FIGUREHIERARCHY_API __declspec(dllexport)
#else
#define FIGUREHIERARCHY_API __declspec(dllimport)
#endif

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