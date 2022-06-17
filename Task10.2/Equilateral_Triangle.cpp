#include "Equilateral_Triangle.h"

// равносторонний треугольник(все стороны равны, все углы равны 60)
Equilateral_Triangle::Equilateral_Triangle(int abc) : Triangle(abc, abc, abc, 60, 60, 60)
    {
        set_name("Равносторонний треугольник");
    }

bool Equilateral_Triangle::check()
    {
        if (!Triangle::check()) return false;
        // Формально, проверять равенство сторон и равенство углов не надо, так как они задаются в конструкторе Triangle равными
        return true;
    }