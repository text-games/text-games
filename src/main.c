#include <ncurses.h>
#include "menu/mainmenu.h"

int main() 
{
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/*menu entry code will go here*/
	

	return startMenu(); 
}

