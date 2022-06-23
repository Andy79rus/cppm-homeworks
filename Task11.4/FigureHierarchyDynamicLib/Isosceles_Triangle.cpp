#include "Isosceles_Triangle.h"

namespace FigureHierarchy
{
    // равнобедренный треугольник (стороны a и c равны, углы A и C равны)
    Isosceles_Triangle::Isosceles_Triangle(int ac, int b, int AC, int B) : Triangle(ac, b, ac, AC, B, AC)
    {
        set_name("Равнобедренный треугольник");
    }

    bool Isosceles_Triangle::check()
    {
        if (!Triangle::check()) return false;
        // Формально, проверять равенство сторон a и с, равенство углов A и C не надо, так как они задаются в конструкторе Triangle равными
        return true;
    }
}