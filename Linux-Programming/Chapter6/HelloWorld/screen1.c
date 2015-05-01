#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main(){

	initscr();						//Every curses application must start with initscr(), end with endwin();

	move(5, 15);						//Set the location of cursor.
	printw("%s", "Hello World!");
	refresh();

	sleep(2);

	endwin();

	exit(EXIT_SUCCESS);
}
