#include <ncurses.h>

int main() 
{
initscr();

cbreak();
noecho();
keypad(stdscr, TRUE);

/*menu entry code will go here*/


endwin();
return 0; 
}

