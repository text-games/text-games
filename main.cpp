#include <iostream>
#include "ncurses.h"

using namespace std;

int main() 
{
initscr();
printw("HI PEOPLE");
refresh();
getch();
endwin();
return 0; 
}

