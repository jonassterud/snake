#pragma once
#include <vector>
#include <ncurses.h>
#include "Display.h"

class Player
{
private:
    // Variables:
    unsigned int x, y;
    signed int xDir, yDir;
    unsigned int length;
    bool dead;
    unsigned int foodX, foodY;
    std::vector<std::vector<unsigned int>> tail;
public:
    // Constructors:
    Player(unsigned int X, unsigned int Y);

    // Functions:
    void draw(WINDOW * win);
    void move(Display &display);
    void spawnFood(Display &display);
    
    // Getters:
    unsigned int getLength();
    bool isDead();
};
