#include <iostream>
#include "ncurses.h"

using namespace std;

int main() 
{
initscr();
printw("HI PEEPULS");
refresh();
getch();
endwin();
return 0; 
}

