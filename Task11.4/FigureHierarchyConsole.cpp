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

    FigureHierarchy::Figure f;
    f.print_info();

    FigureHierarchy::Triangle tri(11, 20, 30, 50, 60, 70);
    tri.print_info();

    FigureHierarchy::Right_Triangle rtri1(11, 20, 30, 50, 60);
    rtri1.print_info();

    FigureHierarchy::Right_Triangle rtri2(11, 20, 30, 50, 40);
    rtri2.print_info();

    FigureHierarchy::Isosceles_Triangle itri(10, 20, 50, 60);
    itri.print_info();

    FigureHierarchy::Equilateral_Triangle etri(30);
    etri.print_info();

    FigureHierarchy::Quadrangle quad(10, 20, 30, 40, 50, 60, 70, 80);
    quad.print_info();

    FigureHierarchy::Rectangle rt(10, 20);
    rt.print_info();

    FigureHierarchy::Square sqr(20);
    sqr.print_info();

    FigureHierarchy::Parallelogram plgm(20, 30, 30, 40);
    plgm.print_info();

    FigureHierarchy::Rhombus rmb(30, 30, 150);
    rmb.print_info();

    return 0;
}