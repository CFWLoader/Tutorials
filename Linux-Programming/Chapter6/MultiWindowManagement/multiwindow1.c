#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main(){
	WINDOW* newWindowPtr;
	WINDOW* popupWindowPtr;
	int xLoop;
	int yLoop;

	char letter = 'a';

	initscr();

	//The window will be filled with characters and refresh.
	move(5, 5);

	printw("%s", "Testing multiple windows");
	refresh();

	for(yLoop = 0; yLoop < LINES - 1; ++yLoop){
		for(xLoop = 0; xLoop < COLS - 1; ++xLoop){
			mvwaddch(stdscr, yLoop, xLoop, letter);
			++letter;
			if(letter > 'z') letter = 'a';
		}
	}

	/*Update the screen.*/
	refresh();

	sleep(2);

	//Create a 10*20 window and add text to it.Drawing it to the screen.
	newWindowPtr = newwin(10, 20, 5, 5);
	mvwprintw(newWindowPtr, 2, 2, "%s", "Hello world");
	mvwprintw(newWindowPtr, 5, 2, "%s", "Notice how very long lines wrap inside the window.");

	wrefresh(newWindowPtr);
	sleep(2);

	//Nothing will happen immediately after you call wrefresh because you do not do something to the new window.
	wrefresh(newWindowPtr);
	sleep(2);

	//Curses will treat the new window's content is changed after call a touchwin for new window and the next wrefresh will do effect.
	touchwin(newWindowPtr);
	wrefresh(newWindowPtr);
	sleep(2);

	//Add another new window with frame.
	popupWindowPtr = newwin(10, 20, 8, 8);
	box(popupWindowPtr, '|', '-');
	mvwprintw(popupWindowPtr, 5, 2, "%s", "Pop up window");
	wrefresh(popupWindowPtr);
	sleep(2);

	//This two new window will display in turn before the clear and delete operation.
	touchwin(newWindowPtr);
	wrefresh(newWindowPtr);
	sleep(2);
	wclear(newWindowPtr);
	wrefresh(newWindowPtr);
	sleep(2);
	delwin(newWindowPtr);
	touchwin(popupWindowPtr);
	wrefresh(popupWindowPtr);
	sleep(2);
	delwin(popupWindowPtr);
	touchwin(stdscr);
	refresh();
	sleep(2);
	endwin();

	exit(EXIT_SUCCESS);
}
