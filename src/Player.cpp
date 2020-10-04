#include "Player.h"
#include "Display.h"
#include <iostream>

Player::Player(unsigned int X, unsigned int Y)
    : x(X), y(Y), xDir(1), yDir(0), length(5), dead(false)
{}

void Player::draw(WINDOW * win)
{
    mvwaddch(win, y, x, '@');
    mvwaddch(win, foodY, foodX, '*');
    wrefresh(win);
}

void Player::move(Display &display)
{
    // Create tail:
    tail.insert(tail.begin(), std::vector<unsigned int>{x, y});
    if(tail.size() > length)
    {
        mvwaddch(display.win, tail.back()[1], tail.back()[0], ' ');
        tail.pop_back();
    }

    // Update position:
    x += xDir;
    y += yDir;
    
    // Teleport on edge hit:
    if(x >= display.xMax - display.xMin)
        x = display.xMin;
    else if(x <= display.xMin - 1)
        x = display.xMax - display.xMin - 1;
    if(y >= display.yMax - display.yMin)
        y = display.yMin;
    else if(y <= display.yMin - 1)
        y = display.yMax - display.yMin - 1;

    // Check for death:
    for(std::vector<unsigned int> v : tail)
    {
        if(x == v[0] && y == v[1])
            dead = true;
    }

    // Check for food:
    if(x == foodX && y == foodY)
    {
        spawnFood(display);
        length++;
    }

    // Change direction:
    unsigned int c = wgetch(display.win);
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

void Player::spawnFood(Display &display)
{
    foodX = display.xMin + (rand() % static_cast<int>(display.xMax - display.xMin + 1));
    foodY = display.yMin + (rand() % static_cast<int>(display.yMax - display.yMin + 1));
}

unsigned int Player::getLength()
{
    return length;
}

bool Player::isDead()
{
    return dead;
}
