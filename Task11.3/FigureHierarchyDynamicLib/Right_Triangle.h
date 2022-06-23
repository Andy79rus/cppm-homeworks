#pragma once
#include "Triangle.h"

#ifdef FIGUREHIERARCHYLIBRARYDYNAMIC_EXPORTS
#define FIGUREHIERARCHY_API __declspec(dllexport)
#else
#define FIGUREHIERARCHY_API __declspec(dllimport)
#endif

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