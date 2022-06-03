#include "Parallelogram.h"

 // параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
Parallelogram::Parallelogram(int ac, int bd, int AC, int BD) : Quadrangle(ac, bd, ac, bd, AC, BD, AC, BD)
    {
        set_name("ѕараллелограмм");
    }

bool Parallelogram::check()
    {
        if (!Quadrangle::check()) return false;
        // ѕравильность равенства противоположных сторон задаетс€ в конструкторе, в проверке нет необходимости.
        // ѕравильность равенства противоположных углов задаетс€ в конструкторе, в проверке нет необходимости.
        const int* c = this->get_corners();
        if (*c == *(c + 1)) return false; // ѕровер€ем, что углы не равны, иначе пр€моугольник/квадрат.
        return true;
    }