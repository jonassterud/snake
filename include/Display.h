#pragma once
#include <ncurses.h>

class Display
{
public:
    // Variables:
    unsigned int yMin, yMax, xMin, xMax;
    WINDOW * win;

    // Constructors:
    Display();
    ~Display();
};
