#pragma once
#include "Figure.h"

#ifdef FIGUREHIERARCHYLIBRARYDYNAMIC_EXPORTS
#define FIGUREHIERARCHY_API __declspec(dllexport)
#else
#define FIGUREHIERARCHY_API __declspec(dllimport)
#endif

namespace FigureHierarchy
{
    // треугольник (стороны и углы произвольные, количество сторон = 3, сумма углов = 180)
    class Triangle : public Figure
    {
    public:
        FIGUREHIERARCHY_API Triangle(int a, int b, int c, int A, int B, int C);
        FIGUREHIERARCHY_API void print_info() override;

    protected:
        bool check() override;
        const int* get_sides();
        const int* get_corners();
        void print_sides();
        void print_corners();

    private:
        void set_sides_abc(int a, int b, int c);
        void set_corners_ABC(int A, int B, int C);
        char sidesName[4] = { 'a', 'b', 'c' };
        char cornersName[4] = { 'A', 'B', 'C' };
        int tri = 3;
        int side_abc[3] = {};
        int corner_ABC[3] = {};
    };
}