#include "mainmenu.h"
#include "../common/nick/nicks-macros.h"
#include <ncurses.h>
#define BLUE_BLOCK 1
typedef enum menuCursorPos {FIRST = 1, SECOND = 2, THIRD = 3, FOURTH = 4, FIFTH = 5} menucursorpos;

menucursorpos mcp_Main = FIRST;

void startMenu()
{
	start_color();
	int row, col;
	int maxr, maxc;
	row = 0;
	col = 0;
	init_pair(BLUE_BLOCK, COLOR_BLUE, COLOR_BLUE);
	mvaddch(0, 0, ACS_BLOCK | A_BLINK | COLOR_PAIR(BLUE_BLOCK));
	forever {
		int ch;
		ch = getch();
		switch (ch) {
			default:
				break;
			case KEY_UP:
				getmaxyx(stdscr, maxr, maxc);
				if (row > 0) {
					mvaddch(row, col, ' ' | A_INVIS);
					row -= 1;
					mvaddch(row, col, ACS_BLOCK | A_BLINK | COLOR_PAIR(BLUE_BLOCK));
				}
				break;
			case KEY_DOWN:
				getmaxyx(stdscr, maxr, maxc);
				if (maxr > (row + 1)) {
					mvaddch(row, col, ' ' | A_INVIS);
					row += 1;
					mvaddch(row, col, ACS_BLOCK | A_BLINK | COLOR_PAIR(BLUE_BLOCK));
				}
				break;
			case KEY_LEFT:
				getmaxyx(stdscr, maxr, maxc);
				if (col > 0) {
					mvaddch(row, col, ' ' | A_INVIS);
					col -= 1;
					mvaddch(row, col, ACS_BLOCK | A_BLINK | COLOR_PAIR(BLUE_BLOCK));
				}
				break;
			case KEY_RIGHT:
				getmaxyx(stdscr, maxr, maxc);
				if (maxc > (col + 1)) {
					mvaddch(row, col, ' ' | A_INVIS);
					col += 1;
					mvaddch(row, col, ACS_BLOCK | A_BLINK | COLOR_PAIR(BLUE_BLOCK));
				}
			break;
		}
	}
}
