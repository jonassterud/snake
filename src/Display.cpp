#include "Display.h"

Display::Display()
{
    // Default options:
    initscr();
    halfdelay(1); // Only wait for input for x-hundred ms
    noecho();
    curs_set(0);

    // Set variables:
    win = newwin(30, 60, 1, 1);
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
