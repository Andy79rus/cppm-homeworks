#pragma once
#include "Triangle.h"

// равносторонний треугольник(все стороны равны, все углы равны 60)
class Equilateral_Triangle : public Triangle
{
public:
    Equilateral_Triangle(int abc);

private:
    bool check() override;
};