#pragma once
#include <vector>
#include <ncurses.h>

class Player
{
private:
    // Variables:
    bool dead;
    signed int xDir, yDir;
    unsigned int x, y, foodX, foodY, length;
    std::vector<std::vector<unsigned int>> tail;
public:
    // Constructors:
    Player(unsigned int X, unsigned int Y);

    // Functions:
    void draw(WINDOW * win);
    void move(WINDOW * win, unsigned int xMin, unsigned int xMax, unsigned int yMin, unsigned int yMax);
    void spawnFood(unsigned int xMin, unsigned int xMax, unsigned int yMin, unsigned int yMax);
    
    // Getters:
    unsigned int getLength();
    bool isDead();
};
