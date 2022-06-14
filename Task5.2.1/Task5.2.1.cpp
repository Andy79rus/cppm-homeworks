#include <iostream>
#include <windows.h>

class Figure
{
public:
    Figure() : Figure(0)
    {}

    void print_sides()
    {
        std::cout << "Стороны: ";
        for (int i = 0; i < this->get_sides_count(); ++i)
            std::cout << sidesName[i] << "=" << *(this->get_sides() + i) << " ";
        std::cout << std::endl;
    }

    void print_corners()
    {
        std::cout << "Углы: ";
        for (int i = 0; i < this->get_corners_count(); ++i)
            std::cout << cornersName[i] << "=" << *(this->get_corners() + i) << " ";
        std::cout << std::endl;

    }

    void print_name()
    {
        std::cout << this->get_name() << ":" << std::endl;
    }

protected:
    Figure(int n)
    {
        set_sides_count(n);
        set_corners_count(n);
        set_name("Фигура");
    }

    void set_sides_count(int n)
    {
        this->sides = n;
    }

    int get_sides_count()
    {
        return this->sides;
    }

    void set_corners_count(int n)
    {
        this->corners = n;
    }

    int get_corners_count()
    {
        return this->corners;
    }

    void set_name(std::string s)
    {
        this->name = s;
    }

    std::string get_name()
    {
        return this->name;
    }

    virtual const int* get_sides()
    {
        return nullptr;
    }
    virtual const int* get_corners()
    {
        return nullptr;
    }

private:
    char sidesName[4] = { 'a', 'b', 'c', 'd' };
    char cornersName[4] = { 'A', 'B', 'C', 'D' };
    int sides;
    int corners;
    std::string name;
};

class Triangle : public Figure
{
public:
    Triangle(int a, int b, int c, int A, int B, int C) : Figure(tri)
    {
        set_sides_abc(a, b, c);
        set_corners_ABC(A, B, C);
        set_corners_count(tri);
        set_sides_count(tri);
        set_name("Треугольник");
    }

private:
    void set_sides_abc(int a, int b, int c)
    {
        this->side_abc[0] = a;
        this->side_abc[1] = b;
        this->side_abc[2] = c;
    }

    void set_corners_ABC(int A, int B, int C)
    {
        this->corner_ABC[0] = A;
        this->corner_ABC[1] = B;
        this->corner_ABC[2] = C;
    }

    const int* get_sides() override
    {
        return this->side_abc;
    }

    const int* get_corners() override
    {
        return this->corner_ABC;
    }

    int tri = 3;
    int side_abc[3] = {};
    int corner_ABC[3] = {};
};

// прямоугольный треугольник (угол C всегда равен 90)
class Right_Triangle : public Triangle
{
public:
    Right_Triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
    {
        set_name("Прямоугольный треугольник");
    }
};

// равнобедренный треугольник (стороны a и c равны, углы A и C равны)
class Isosceles_Triangle : public Triangle
{
public:
    Isosceles_Triangle(int ac, int b, int AC, int B) : Triangle(ac, b, ac, AC, B, AC)
    {
        set_name("Равнобедренный треугольник");
    }
};

// равносторонний треугольник(все стороны равны, все углы равны 60)
class Equilateral_Triangle : public Triangle
{
public:
    Equilateral_Triangle(int abc) : Triangle(abc, abc, abc, 60, 60, 60)
    {
        set_name("Равносторонний треугольник");
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(quad)
    {
        set_sides_abcd(a, b, c, d);
        set_corners_ABCD(A, B, C, D);
        set_corners_count(quad);
        set_sides_count(quad);
        set_name("Четырехугольник");
    }

private:
    void set_sides_abcd(int a, int b, int c, int d)
    {
        this->side_abcd[0] = a;
        this->side_abcd[1] = b;
        this->side_abcd[2] = c;
        this->side_abcd[3] = d;
    }
    void set_corners_ABCD(int A, int B, int C, int D)
    {
        this->corner_ABCD[0] = A;
        this->corner_ABCD[1] = B;
        this->corner_ABCD[2] = C;
        this->corner_ABCD[3] = D;
    }

    const int* get_sides() override
    {
        return this->side_abcd;
    }

    const int* get_corners() override
    {
        return this->corner_ABCD;
    }

    int quad = 4;
    int side_abcd[4] = {};
    int corner_ABCD[4] = {};
};

// прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90)
class Rectangle : public Quadrangle
{
public:
    Rectangle(int ac, int bd) : Quadrangle(ac, bd, ac, bd, 90, 90, 90, 90)
    {
        set_name("Прямоугольник");
    }
};

// квадрат (все стороны равны, все углы равны 90)
class Square : public Rectangle
{
public:
    Square(int abcd) : Rectangle(abcd, abcd)
    {
        set_name("Квадрат");
    }
};

// параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int ac, int bd, int AC, int BD) : Quadrangle(ac, bd, ac, bd, AC, BD, AC, BD)
    {
        set_name("Параллелограмм");
    }
};

// ромб (все стороны равны, углы A,C и B,D попарно равны)
class Rhombus : public Parallelogram
{
public:
    Rhombus(int abcd, int AC, int BD) : Parallelogram(abcd, abcd, AC, BD)
    {
        set_name("Ромб");
    }
};

void print_info(Figure* a_fig)
{
    a_fig->print_name();
    a_fig->print_sides();
    a_fig->print_corners();
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Triangle tri(33, 45, 11, 26, 68, 94);
    print_info(&tri);

    Right_Triangle rtri(20, 12, 26, 40, 50);
    print_info(&rtri);

    Isosceles_Triangle itri(27, 12, 40, 100);
    print_info(&itri);

    Equilateral_Triangle etri(15);
    print_info(&etri);

    Quadrangle quad(14, 15, 16, 17, 30, 40, 50, 60);
    print_info(&quad);

    class Rectangle rt(20, 30);
    print_info(&rt);

    Square sqr(8);
    print_info(&sqr);

    Parallelogram plgm(10, 31, 40, 80);
    print_info(&plgm);

    Rhombus rmb(10, 30, 120);
    print_info(&rmb);

    return 0;
}