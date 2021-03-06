#pragma once
#include <ncurses.h>

class Display
{
public:
    // Variables:
    unsigned int yMin, yMax, xMin, xMax;
    WINDOW * win;

    // Constructors:
    Display(unsigned int yBegin, unsigned int xBegin, unsigned int lines, unsigned int cols);
    ~Display();
};
