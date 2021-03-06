#pragma once
#include "Parallelogram.h"

namespace FigureHierarchy
{
    // ромб (все стороны равны, углы A,C и B,D попарно равны)
    class Rhombus : public Parallelogram
    {
    public:
        FIGUREHIERARCHY_API Rhombus(int abcd, int AC, int BD);

    protected:
        bool check() override;
    };
}