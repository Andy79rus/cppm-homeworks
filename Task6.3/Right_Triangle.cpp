#include "Right_Triangle.h"

 // прямоугольный треугольник (угол C всегда равен 90)
Right_Triangle::Right_Triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
    {
        set_name("Прямоугольный треугольник");
    }

bool Right_Triangle::check()
    {
        if (!Triangle::check()) return false;
        // Формально, проверять угол С не надо, так как они задаются в конструкторе Triangle равным 90
        return true;
    }