#include "Parallelogram.h"

    // параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
    Parallelogram::Parallelogram(int ac, int bd, int AC, int BD) : Parallelogram(ac,bd, AC, BD, "Параллелограмм")
    {}

    Parallelogram::Parallelogram(int ac, int bd, int AC, int BD, const std::string& name) : Quadrangle(ac, bd, ac, bd, AC, BD, AC, BD, name)
    {}