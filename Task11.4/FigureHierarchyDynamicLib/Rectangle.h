#pragma once
#include "Quadrangle.h"

#ifdef FIGUREHIERARCHYLIBRARYDYNAMIC_EXPORTS
#define FIGUREHIERARCHY_API __declspec(dllexport)
#else
#define FIGUREHIERARCHY_API __declspec(dllimport)
#endif

namespace FigureHierarchy
{
    // ������������� (������� a,c � b,d ������� �����, ��� ���� ����� 90)
    class Rectangle : public Quadrangle
    {
    public:
        FIGUREHIERARCHY_API Rectangle(int ac, int bd);

    protected:
        bool check() override;
    };
}