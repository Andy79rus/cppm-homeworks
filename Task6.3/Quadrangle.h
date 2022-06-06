#pragma once
#include "Figure.h"

// четырёхугольник (стороны и углы произвольные, количество сторон = 4, сумма углов = 360)
class Quadrangle : public Figure
{
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
    void print_info() override;

protected:
    bool check() override;
    const int* get_sides() override;
    const int* get_corners() override;

private:
    void set_sides_abcd(int a, int b, int c, int d);
    void set_corners_ABCD(int A, int B, int C, int D);
    int quad = 4;
    int side_abcd[4] = {};
    int corner_ABCD[4] = {};
};