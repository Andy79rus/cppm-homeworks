#include <iostream>
#include <windows.h>
#include "Figure.h"
#include "Triangle.h"
#include "Right_Triangle.h"
#include "Isosceles_Triangle.h"
#include "Equilateral_Triangle.h"
#include "Quadrangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Figure f;
    f.print_info();

    Triangle tri(11, 20, 30, 50, 60, 70);
    tri.print_info();

    Right_Triangle rtri1(11, 20, 30, 50, 60);
    rtri1.print_info();

    Right_Triangle rtri2(11, 20, 30, 50, 40);
    rtri2.print_info();

    Isosceles_Triangle itri(10, 20, 50, 60);
    itri.print_info();

    Equilateral_Triangle etri(30);
    etri.print_info();

    Quadrangle quad(10, 20, 30, 40, 50, 60, 70, 80);
    quad.print_info();

    class Rectangle rt(10, 20);
    rt.print_info();

    Square sqr(20);
    sqr.print_info();

    Parallelogram plgm(20, 30, 30, 40);
    plgm.print_info();

    Rhombus rmb(30, 30, 150);
    rmb.print_info();

    return 0;
}