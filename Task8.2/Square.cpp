#include "Square.h"

    // квадрат (все стороны равны, все углы равны 90)
    Square::Square(int abcd) : Rectangle(abcd, abcd, "Квадрат")
    {}

    bool Square::check()
    {
        if (!Rectangle::check()) return false;
        return true;
    }