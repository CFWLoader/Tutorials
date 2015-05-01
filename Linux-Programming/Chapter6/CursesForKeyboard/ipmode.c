#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#define PASSWORD_LENGTH 256
#define NAME_LENGTH 128

int main(){
	char name[NAME_LENGTH];
	char password[PASSWORD_LENGTH];

	const char* realPassword = "xyzzy";

	int i = 0;

	initscr();

	move(5, 10);
	printw("%s", "Please login:");

	move(7, 10);
	printw("%s", "Username:");
	getstr(name);

	move(8, 10);
	printw("%s", "Password:");
	refresh();

	cbreak();
	noecho();

	memset(password, '\0', sizeof(password));

	while(i < PASSWORD_LENGTH){
		password[i] = getch();
		if(password[i] == '\n') break;
		move(8, 20 + i);
		addch('*');
		refresh();
		++i;
	}

	echo();
	nocbreak();

	move(11, 10);
	if(strncmp(realPassword, password, strlen(realPassword)) == 0){
		printw("%s", "Correct");
	} else {
		printw("%s", "Wrong");
	}

	printw("%s", password);

	refresh();
	sleep(2);

	endwin();
	
	exit(EXIT_SUCCESS);
}

