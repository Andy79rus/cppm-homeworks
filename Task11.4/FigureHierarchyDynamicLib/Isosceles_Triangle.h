#pragma once
#include "Triangle.h"

#ifdef FIGUREHIERARCHYLIBRARYDYNAMIC_EXPORTS
#define FIGUREHIERARCHY_API __declspec(dllexport)
#else
#define FIGUREHIERARCHY_API __declspec(dllimport)
#endif

namespace FigureHierarchy
{
    // �������������� ����������� (������� a � c �����, ���� A � C �����)
    class Isosceles_Triangle : public Triangle
    {
    public:
        FIGUREHIERARCHY_API Isosceles_Triangle(int ac, int b, int AC, int B);

    private:
        bool check() override;
    };
}