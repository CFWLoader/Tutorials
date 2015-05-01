#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

int main(){

	const char witchOne[] = " First Witch   ";
	const char witchTwo[] = " Seconde Witch ";
	const char *scanPtr;

	initscr();

	move (5, 15);

	attron(A_BOLD);
	printw("%s", "Macbeth");
	attroff(A_BOLD);

	refresh();

	sleep(1);

	move(8, 15);

	attron(A_STANDOUT);
	printw("%s", "Thunder and Lightning");
	attroff(A_STANDOUT);

	refresh();
	sleep(1);

	move(10, 10);
	printw("%s", "When shall we three meet again?");

	move(11, 23);
	printw("%s", "In thunder, lightning, or in rain?");

	move(13, 10);
	printw("%s", "When the hurlyburly's done,");

	move(14, 23);
	printw("%s", "When the battle's lost and won.");

	refresh();
	
	sleep(1);

	attron(A_DIM);
	scanPtr = witchOne + strlen(witchOne) - 1;

	while(scanPtr != witchOne){
		move(10, 10);
		insch(*scanPtr--);
	}

	scanPtr = witchTwo + strlen(witchTwo) - 1;

	while(scanPtr != witchTwo){
		move(13, 10);
		insch(*scanPtr--);
	}

	attroff(A_DIM);

	refresh();
	sleep(1);

	move(LINES - 1, COLS - 1);

	refresh();

	sleep(1);

	endwin();

	exit(EXIT_SUCCESS);

}
