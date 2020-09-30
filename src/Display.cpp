#include "Display.h"

Display::Display(unsigned int lines, unsigned int cols, unsigned int yBegin, unsigned int xBegin)
{
    // Default options:
    initscr();
    halfdelay(1); // Only wait for input for x-hundred ms
    noecho();
    curs_set(0);

    // Set variables:
    win = newwin(lines, cols, yBegin, xBegin);
    getbegyx(win, yMin, xMin);
    getmaxyx(win, yMax, xMax);
    refresh();
    keypad(win, true);

    // Draw border:
    box(win, 0, 0);
    wrefresh(win);
}

Display::~Display()
{
    endwin();
}
