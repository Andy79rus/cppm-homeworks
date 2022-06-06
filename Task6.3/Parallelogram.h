#pragma once
#include "Quadrangle.h"

// параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int ac, int bd, int AC, int BD);

protected:
    bool check() override;
};