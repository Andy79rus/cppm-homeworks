#pragma once
#include "Triangle.h"

// равнобедренный треугольник (стороны a и c равны, углы A и C равны)
class Isosceles_Triangle : public Triangle
{
public:
    Isosceles_Triangle(int ac, int b, int AC, int B);

private:
    bool check() override;
};