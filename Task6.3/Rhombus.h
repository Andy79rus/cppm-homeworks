#pragma once
#include "Parallelogram.h"

// ромб (все стороны равны, углы A,C и B,D попарно равны)
class Rhombus : public Parallelogram
{
public:
    Rhombus(int abcd, int AC, int BD);

protected:
    bool check() override;
};