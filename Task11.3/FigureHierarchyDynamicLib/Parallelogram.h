#pragma once
#include "Quadrangle.h"

#ifdef FIGUREHIERARCHYLIBRARYDYNAMIC_EXPORTS
#define FIGUREHIERARCHY_API __declspec(dllexport)
#else
#define FIGUREHIERARCHY_API __declspec(dllimport)
#endif

namespace FigureHierarchy
{
    // параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
    class Parallelogram : public Quadrangle
    {
    public:
        FIGUREHIERARCHY_API Parallelogram(int ac, int bd, int AC, int BD);

    protected:
        bool check() override;
    };
}