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
#include "ErrorEx.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure* f = nullptr;

    try
    {
        f = new Quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    try
    {
        f = new Square(0);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    try
    {
        f = new Equilateral_Triangle(10);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    try
    {
        f = new Right_Triangle(11, 20, 30, 50, 60);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    try
    {
        f = new Right_Triangle(11, 20, 30, 50, 40);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    try
    {
        f = new Isosceles_Triangle(10, 20, 50, 60);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    try
    {
        f = new Equilateral_Triangle(30);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    try
    {
        f = new Quadrangle(10, 20, 30, 40, 150, 60, 70, 80);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    try
    {
        f = new class Rectangle(10, 20);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    try
    {
        f = new Square(20);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    try
    {
        f = new Parallelogram(20, 30, 30, 40);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    try
    {
        f = new Rhombus(30, 30, 150);
        f->print_info(true);
        std::cout << std::endl;
    }
    catch (const FigureHierarhyException& ex)
    {
        std::cout << "Причина: " << ex.what() << std::endl << std::endl;
    }
    catch (...)
    {
        std::cout << "Причина: Неизвестная ошибка" << std::endl;
    }

    delete f;

    return 0;
}