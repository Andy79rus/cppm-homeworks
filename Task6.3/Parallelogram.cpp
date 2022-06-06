#include "Parallelogram.h"

// параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
Parallelogram::Parallelogram(int ac, int bd, int AC, int BD) : Quadrangle(ac, bd, ac, bd, AC, BD, AC, BD)
    {
        set_name("Параллелограмм");
    }

bool Parallelogram::check()
    {
        if (!Quadrangle::check()) return false;
        // Правильность равенства противоположных сторон задается в конструкторе, в проверке нет необходимости.
        // Правильность равенства противоположных углов задается в конструкторе, в проверке нет необходимости.
        const int* c = this->get_corners();
        if (*c == *(c + 1)) return false; // Проверяем, что углы не равны, иначе прямоугольник/квадрат.
        return true;
    }