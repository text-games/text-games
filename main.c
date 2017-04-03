#include "ncurses.h"

int main() 
{
initscr();
printw("HI PEOPLE"); /*HI CODERS, THIS IS C CODE*/
refresh();
getch();
endwin();
return 0; 
}

