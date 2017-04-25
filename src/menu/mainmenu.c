#include "mainmenu.h"
#include "../common/nick/nicks-macros.h"
#include <ncurses.h>
#include <stdlib.h>
#include "../pong/pong.h"
#define BLUE_BLOCK 1
#define RED_CHAR 2
#define MAX_OPTS 2
typedef enum menuCursorPos {FIRST = 1, SECOND = 2, THIRD = 3, FOURTH = 4, FIFTH = 5} menucursorpos;

menucursorpos mcp_Main = FIRST;

int startMenu()
{
	start_color();
	init_pair(BLUE_BLOCK, COLOR_BLUE, COLOR_BLACK);
	init_pair(RED_CHAR, COLOR_RED, COLOR_BLACK);
	mvprintw(0, 1, "Pong");
	mvprintw(1, 1, "Quit");
	mvaddch(0, 0, ACS_RARROW | A_BLINK | COLOR_PAIR(RED_CHAR));
	forever {
		int ch;
		ch = getch();
		switch (ch) {
			default:
				break;
			case KEY_UP:
				if (mcp_Main > 1) {
					mvaddch(mcp_Main-1, 0, ' ' | A_INVIS);
					--mcp_Main;
					mvaddch(mcp_Main-1, 0, ACS_RARROW | A_BLINK | COLOR_PAIR(RED_CHAR));
				}
				break;
			case KEY_DOWN:
				if (mcp_Main < MAX_OPTS) {
					mvaddch(mcp_Main-1, 0, ' ' | A_INVIS);
					++mcp_Main;
					mvaddch(mcp_Main-1, 0, ACS_RARROW | A_BLINK | COLOR_PAIR(RED_CHAR));
				}
				break;
			case KEY_RIGHT:
				switch (mcp_Main) {
					default:
						break;
					case FIRST:
						return startPong();
						break;
					case SECOND:
						endwin();
						return 0;
						break;
				}
				break;
		}
	}
}
