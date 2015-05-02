#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

#define LOCAL_ESCAPE_KEY 27

int main(){

	int key;

	//Initialization and turn on keypad.
	initscr();

	crmode();

	keypad(stdscr, TRUE);

	//Close echo to prevent happening move of cursor after you press down key.
	//Clear the screen and display text.This program will wait for user to hit key.
	//The key's ascii value will display on screen unless the key is Q or error happened.
	
	noecho();

	clear();

	mvprintw(5, 5, "Key pad demonstration, Press 'q' to quit");

	move(7, 5);

	refresh();

	key = getch();

	while(key != ERR && key != 'q'){
		move(7, 5);
		clrtoeol();

		if((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')){
			printw("Key was %c", (char)key);
		} else {
			switch(key){
				case LOCAL_ESCAPE_KEY : printw("%s", "Escape key"); break;
				case KEY_END: printw("%s", "END key");break;
				case KEY_BEG: printw("%s", "BEGINNING KEY"); break;
				case KEY_RIGHT: printw("%s", "RIGHT KEY"); break;
				case KEY_LEFT: printw("%s", "LEFT KEY"); break;
				case KEY_UP: printw("%s", "UP KEY"); break;
				case KEY_DOWN: printw("%s", "DOWN KEY"); break;
				default: printw("Unmatched - %d", key); break;
			}
		}

		refresh();
		key = getch();
	}

	endwin();

	exit(EXIT_SUCCESS);
}
