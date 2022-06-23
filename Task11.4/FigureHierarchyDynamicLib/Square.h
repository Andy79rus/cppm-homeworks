#pragma once
#include "Rectangle.h"

#ifdef FIGUREHIERARCHYLIBRARYDYNAMIC_EXPORTS
#define FIGUREHIERARCHY_API __declspec(dllexport)
#else
#define FIGUREHIERARCHY_API __declspec(dllimport)
#endif

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