#include <iostream>
#include <windows.h>

class Figure
{
public:
    Figure() : Figure(0)
    {
        set_name("Фигура");
    }

    int get_sides_count()
    {
        return this->sides;
    }

    std::string get_name()
    {
        return this->name;
    }

protected:
    Figure(int n)
    {
        set_sides(n);
    }

    void set_name(std::string s)
    {
        this->name = s;
    }

    void set_sides(int n)
    {
        this->sides = n;
    }

private:
    int sides;
    std::string name;
};

class Triangle : public Figure
{
public:
    Triangle() : Figure(3)
    {
        set_name("Треугольник");
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle() : Figure(4)
    {
        set_name("Четырехугольник");
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
 
    Figure fig;
    Triangle tri;
    Quadrangle quad;

    std::cout << "Количество сторон: " << std::endl;
    std::cout << fig.get_name() << ": " << fig.get_sides_count() << std::endl;
    std::cout << tri.get_name() << ": " << tri.get_sides_count() << std::endl;
    std::cout << quad.get_name() << ": " << quad.get_sides_count() << std::endl;

    return 0;
}