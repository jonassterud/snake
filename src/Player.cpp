#include "Player.h"
#include <iostream>

Player::Player(unsigned int X, unsigned int Y)
{
    x = X;
    y = Y;
    xDir = 1;
    yDir = 0;
    length = 5;
    dead = false;
}

void Player::draw(WINDOW * win)
{
    mvwaddch(win, y, x, '@');
    mvwaddch(win, foodY, foodX, '*');
    wrefresh(win);
}

void Player::move(WINDOW * win, unsigned int xMin, unsigned int xMax, unsigned int yMin, unsigned int yMax)
{
    // Create tail:
    tail.insert(tail.begin(), std::vector<unsigned int>{x, y});
    if(tail.size() > length)
    {
        mvwaddch(win, tail.back()[1], tail.back()[0], ' ');
        tail.pop_back();
    }

    // Update position:
    x += xDir;
    y += yDir;
    
    // Teleport on edge hit:
    if(x >= xMax - xMin)
        x = xMin;
    else if(x <= xMin - 1)
        x = xMax - xMin - 1;
    if(y >= yMax - yMin)
        y = yMin;
    else if(y <= yMin - 1)
        y = yMax - yMin - 1;

    // Check for death:
    for(std::vector<unsigned int> v : tail)
    {
        if(x == v[0] && y == v[1])
            dead = true;
    }

    // Check for food:
    if(x == foodX && y == foodY)
    {
        spawnFood(xMin, xMax, yMin, yMax);
        length++;
    }

    // Change direction:
    unsigned int c = wgetch(win);
    switch(c)
    {
        case 97:    // Left
            if(xDir == 0)
            {
                xDir = -1;
                yDir = 0;
            }
            break;
        case 119:   // Up
            if(yDir == 0)
            {
                yDir = -1;
                xDir = 0;
            }
            break;
        case 100:   // Right
            if(xDir == 0)
            {
                xDir = 1;
                yDir = 0;
            }
            break;
        case 115:   // Down
            if(yDir == 0)
            {
                yDir = 1;
                xDir = 0;
            }
            break;
    }
}

void Player::spawnFood(unsigned int xMin, unsigned int xMax, unsigned int yMin, unsigned int yMax)
{
    foodX = xMin + (rand() % static_cast<int>(xMax - xMin + 1));
    foodY = yMin + (rand() % static_cast<int>(yMax - yMin + 1));
}

unsigned int Player::getLength()
{
    return length;
}

bool Player::isDead()
{
    return dead;
}
