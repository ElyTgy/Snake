#include "Game.h"
#include "curses.h"
#include "Utils.h"
#include <ctime>

//call refresh to show stuff
//printw() std::cout
//endwin() restart
//move(y, x)

//LINES = number of rows
//COLS = number of columns

//getmaxy(stdscre, yVariable, xVariable)

//clear screen

//noecho() dont show characters

//no delay() getch() wont block evrythinh elde

//keypad(stdscr, true)enables the arrow keys

int main()
{
	Game g;
	g.run();
	EXIT_SUCCESS;
}

