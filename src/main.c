#include <ncurses.h>
#include "menu/mainmenu.h"

int main() 
{
initscr();

cbreak();
noecho();
keypad(stdscr, TRUE);

/*menu entry code will go here*/
startMenu();

endwin();
return 0; 
}

