#pragma once
#include <iostream>

// фигура(количество сторон = 0)
class Figure
{
public:
    Figure();
    virtual void print_info();

protected:
    Figure(int n);
    virtual bool check();
    void print_check();
    void print_sides_count();
    void print_name();
    void set_sides_count(int n);
    int get_sides_count();
    void set_corners_count(int n);
    int get_corners_count();
    void set_name(std::string s);
    std::string get_name();

private:
    int sides;
    int corners;
    std::string name;
};