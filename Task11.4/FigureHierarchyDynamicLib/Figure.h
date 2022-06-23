#pragma once
#include <iostream>

#ifdef FIGUREHIERARCHYLIBRARYDYNAMIC_EXPORTS
#define FIGUREHIERARCHY_API __declspec(dllexport)
#else
#define FIGUREHIERARCHY_API __declspec(dllimport)
#endif

namespace FigureHierarchy
{
    // фигура(количество сторон = 0)
    class Figure
    {
    public:
        FIGUREHIERARCHY_API Figure();
        FIGUREHIERARCHY_API virtual void print_info();

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
}