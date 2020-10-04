#include <iostream>
#include <ncurses.h>
#include "Display.h"
#include "Player.h"

int main()
{
    // Initiate objects:
    Display display(30, 60, 1, 1);
    Player player(display.xMin, display.yMin + 1);

    // Loop:
    player.spawnFood(display);
    while(!player.isDead())
    {
        // Draw and move:
        player.draw(display.win);
        player.move(display);

        // Draw score:
        std::string score = "Score: " + std::to_string(player.getLength());
        mvwprintw(display.win, 1, 1, score.c_str());
        wrefresh(display.win);
    }

    // End:
    getch();
}
