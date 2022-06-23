#pragma once
#include "Parallelogram.h"

#ifdef FIGUREHIERARCHYLIBRARYDYNAMIC_EXPORTS
#define FIGUREHIERARCHY_API __declspec(dllexport)
#else
#define FIGUREHIERARCHY_API __declspec(dllimport)
#endif

namespace FigureHierarchy
{
    // ���� (��� ������� �����, ���� A,C � B,D ������� �����)
    class Rhombus : public Parallelogram
    {
    public:
        FIGUREHIERARCHY_API Rhombus(int abcd, int AC, int BD);

    protected:
        bool check() override;
    };
}