#include <iostream>
#include <ncurses.h>
#include "Display.h"
#include "Player.h"

int main()
{
    // Initiate objects:
    Display display;
    Player player(display.xMin, display.yMin);

    // Basic player actions:
    player.spawnFood(display.xMin, display.yMax, display.yMin, display.yMax);
    while(!player.isDead())
    {
        player.draw(display.win);
        player.move(display.win, display.xMin, display.xMax, display.yMin, display.yMax);
    }
    
    // End:
    getch();
}
