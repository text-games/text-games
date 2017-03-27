#include "ncurses.h"

int main() 
{
initscr();
printw("HI PEOPLE"); /*HI CODERS*/
refresh();
getch();
endwin();
return 0; 
}

