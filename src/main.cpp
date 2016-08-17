#include <iostream>
#include <string>
#include <ncurses.h>
#include "Material.h"
#include "Calculations.h"
#include "Chunk.h"
#include "Renderer.h"

using namespace std;

Chunk ch;

int main()
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    attron(A_BOLD);
    printw("Space Fortress");
    attroff(A_BOLD);
    printw(" (Working Title)\n");
    refresh();
    getch();
    ch.tiles[4][4].attributes[0] = true;
    printw(render(ch).c_str());
    refresh();
    getch();
    endwin();

    return 0;
}