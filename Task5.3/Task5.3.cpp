#include <iostream>
#include <windows.h>

// фигура(количество сторон = 0)
class Figure
{
public:
    Figure() : Figure(0)
    {}

    virtual void print_info()
    {
        print_name();
        print_check();
        print_sides_count();
        std::cout << std::endl;
    }

protected:
    Figure(int n)
    {
        set_sides_count(n);
        set_corners_count(n);
        set_name("Фигура");
    }

    virtual bool check()
    {
        return true; // базовая фигура правильная по-умолчанию
    }

    void print_check()
    {
        std::string status;
        (this->check()) ? status = "Правильная" : status = "Неправильная";
        std::cout << status << std::endl;
    }

    void print_sides_count()
    {
        std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
    }

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

// треугольник (стороны и углы произвольные, количество сторон = 3, сумма углов = 180)
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

    void print_info() override
    {
        print_name();
        print_check();
        print_sides_count();
        print_sides();
        print_corners();
        std::cout << std::endl;
    }

protected:
    bool check() override
    {
        const int* s = this->get_sides();
        int s_count = this->get_sides_count();
        for (int i = 0; i < s_count; ++i)
        {
            if (*(s + i) <= 0) return false; // Проверяем, что длины сторон больше нуля.
        }
        // Cумма длин любых двух сторон должна быть строго больше длинны третей стороны.
        if ((*s >= *(s + 1) + *(s + 2)) || (*(s + 1) >= *s + *(s + 2)) || (*(s + 2) >= *s + *(s + 1))) return false;
        const int* c = this->get_corners();
        int c_count = this->get_sides_count();
        int corners_sum = 0;
        for (int i = 0; i < c_count; ++i)
        {
            corners_sum += *(c + i);
        }
        if (180 != corners_sum) return false; // Проверяем, что сумма углов фигуры равна 180.
        return true;    
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

private:
    bool check() override
    {
        if (!Triangle::check()) return false;
        // Формально, проверять угол С не надо, так как они задаеются в конструкторе Triangle равным 90
        return true;
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

private:
    bool check() override
    {
        if (!Triangle::check()) return false;
        // Формально, проверять равенство сторон a и с, равенство углов A и C не надо, так как они задаеются в конструкторе Triangle равными
        return true;
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

private:
    bool check() override
    {
        if (!Triangle::check()) return false;
        // Формально, проверять равенство сторон и равенство углов не надо, так как они задаеются в конструкторе Triangle равными
        return true;
    }
};

// четырёхугольник (стороны и углы произвольные, количество сторон = 4, сумма углов = 360)
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

    void print_info() override
    {
        print_name();
        print_check();
        print_sides_count();
        print_sides();
        print_corners();
        std::cout << std::endl;
    }

protected:
    const int* get_sides() override
    {
        return this->side_abcd;
    }

    const int* get_corners() override
    {
        return this->corner_ABCD;
    }

    bool check() override
    {
        const int* s = this->get_sides();
        int s_count = this->get_sides_count();
        for (int i = 0; i < s_count; ++i)
        {
            if (*(s + i) <= 0) return false; // Проверяем, что длины сторон больше нуля.
        }
        const int* c = this->get_corners();
        int c_count = this->get_sides_count();
        int corners_sum = 0;
        for (int i = 0; i < c_count; ++i)
        {
            corners_sum += *(c + i);
        }
        if (360 != corners_sum) return false; // Проверяем, что сумма углов фигуры равна 360.
        return true;        
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

protected:
    bool check() override
    {
        if (!Quadrangle::check()) return false;
        // Правильность равенства противоположных сторон задается в конструкторе, в проверке нет необходимости.
        /* Формально, проверять углы не надо, так как они задаеются в конструкторе Quadrangle равные 90
        const int* c = this->get_corners();
        int c_count = this->get_sides_count();
        for (int i = 0; i < c_count; ++i)
        {
            if (90 != *(c + i)) return false; // Проверяем, что углы равны 90
        }
        */
        return true;
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

protected:
    bool check() override
    {
        if (!Quadrangle::check()) return false;
        if (!Rectangle::check()) return false;
        return true;
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

protected:
    bool check() override
    {
        if (!Quadrangle::check()) return false;
        // Правильность равенства противоположных сторон задается в конструкторе, в проверке нет необходимости.
        // Правильность равенства противоположных углов задается в конструкторе, в проверке нет необходимости.
        const int* s = this->get_sides();
        const int* c = this->get_corners();
        if ((*s == *(s+1)) || (*c == *(c+1))) return false; // Проверяем, что длины соседних сторон или углов не равны, иначе прямоугольник/ромб/квадрат.
        return true;
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

protected:
    bool check() override
    {
        if (!Quadrangle::check()) return false;
        if (!Parallelogram::check())
        {
            const int* c = this->get_corners();
            if ((*c == *(c+1))) return false; // Проверяем, что соседние углы не равны 360/4=90, иначе квадрат (хотя квадрат это частный случай ромба)
        }
        return true;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Figure f;
    f.print_info();

    Triangle tri(33, 45, 11, 26, 68, 94);
    tri.print_info();

    Right_Triangle rtri(20, 12, 26, 40, 50);
    rtri.print_info();

    Isosceles_Triangle itri(27, 12, 40, 100);
    itri.print_info();

    Equilateral_Triangle etri(15);
    etri.print_info();

    Quadrangle quad(14, 15, 16, 17, 30, 40, 50, 60);
    quad.print_info();

    class Rectangle rt(20, 30);
    rt.print_info();

    Square sqr(8);
    sqr.print_info();

    Parallelogram plgm(10, 31, 140, 40);
    plgm.print_info();

    Rhombus rmb(10, 30, 140);
    rmb.print_info();

    return 0;
}