#include "Rhombus.h"

// ромб (все стороны равны, углы A,C и B,D попарно равны)
Rhombus::Rhombus(int abcd, int AC, int BD) : Parallelogram(abcd, abcd, AC, BD)
    {
        set_name("Ромб");
    }

bool Rhombus::check()
    {
        if (!Parallelogram::check()) return false;
        /*
           Проверяем, что соседние углы не равны 360 / 4 = 90, иначе это квадрат(хотя квадрат это частный случай ромба)
           const int* c = this->get_corners();
           if ((*c == *(c+1))) return false;
        */
        return true;
    }