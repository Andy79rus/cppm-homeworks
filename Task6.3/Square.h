#pragma once
#include "Rectangle.h"

 // квадрат (все стороны равны, все углы равны 90)
class Square : public Rectangle
{
public:
    Square(int abcd);

protected:
    bool check() override;
};
