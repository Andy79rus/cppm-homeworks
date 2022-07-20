#include "Rhombus.h"

    // ромб (все стороны равны, углы A,C и B,D попарно равны)
    Rhombus::Rhombus(int abcd, int AC, int BD) : Parallelogram(abcd, abcd, AC, BD, "Ромб")
    {}