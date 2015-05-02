#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main(){

	//Initializing codes.
	WINDOW* subWindowPtr;

	int xLoop;
	int yLoop;
	int counter;
	char letter = '1';

	initscr();

	for(yLoop = 0; yLoop < LINES - 1; ++yLoop){
		for(xLoop = 0; xLoop < COLS - 1; ++xLoop){
			mvwaddch(stdscr, yLoop, xLoop, letter);
			++letter;
			if(letter > '9') letter = '1';
		}
	}

	//Creating a scroll sub window.We must call touchwin before wrefresh.
	subWindowPtr = subwin(stdscr, 10, 20, 10, 10);
	scrollok(subWindowPtr, 1);

	touchwin(stdscr);
	refresh();
	sleep(1);

	//Clear old text and fill with news.Refresh it.
	werase(subWindowPtr);
	mvwprintw(subWindowPtr, 2, 0, "%s", "This window will now scroll.");
	wrefresh(subWindowPtr);

	sleep(1);

	for(counter = 1; counter < 10; ++counter){
		wprintw(subWindowPtr, "%s", "This text is both wrapping and scrolling.");
		wrefresh(subWindowPtr);

		sleep(1);
	}

	//Delete the sub window and refresh the basic screen before the end of program.
	delwin(subWindowPtr);

	touchwin(stdscr);

	refresh();

	sleep(1);

	endwin();

	exit(EXIT_SUCCESS);
}
