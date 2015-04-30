#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <term.h>
#include <curses.h>

static FILE* output_stream = (FILE*)0;

char* menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL
};

int getChoice(char* greet, char* choices[], FILE* in, FILE* out);

//Added in menu3-adv.c
int char_to_terminal(int charToWrite);
//End

int main(){

	int choice = 0;

	FILE* input;
	FILE* output;

	//Add new clause here.
	struct termios initial_settings, new_settings;

	if(!isatty(fileno(stdout))){
		fprintf(stderr, "You are not a terminal!\n");
	}

	input = fopen("/dev/tty", "r");
	output = fopen("/dev/tty", "w");

	if(!input || !output){
		fprintf(stderr, "Unable to open /dev/tty\n");
		exit(1);
	}

	tcgetattr(fileno(input), &initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_lflag &= ~ISIG;

	if(tcsetattr(fileno(input), TCSANOW, &new_settings) != 0){
		fprintf(stderr, "Could'n set attributes\n");
	}

	do{
		choice = getChoice("Please select an action", menu, input, output);
		printf("You have chose: %c\n", choice);
		sleep(1);
	}while(choice != 'q');

	tcsetattr(fileno(input), TCSANOW, &initial_settings);

	exit(0);
}

int getChoice(char* greet, char* choices[], FILE* in, FILE* out){

	int chosen = 0;
	int selected;

	//Added in menu3-adv.c.
	int screenrow, screencol = 10;
	char *cursor, *clear;
	//End.

	char** option;

	//Added in menu3-adv.c
	output_stream = out;

	setupterm(NULL, fileno(out), (int*)0);
	cursor = tigetstr("cup");
	clear = tigetstr("clear");

	screenrow = 4;

	tputs(clear, 1, (int*) char_to_terminal);
	tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);

	fprintf(out, "%s\n", greet);

	screenrow += 2;

	option = choices;

	while(*option){
		tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
		fprintf(out, "%s", *option);
		++screenrow;
		++option;
	}

	fprintf(out, "\n");

	do{
		fflush(out);
		selected = fgetc(in);
		option = choices;
		
		while(*option){
			if(selected == *option[0]){
				chosen = 1;
				break;
			}
			++option;
		}

		if(!chosen){
			tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
			fprintf(out, "Incorrect choice, select again\n");
		}
	}while(!chosen);

	tputs(clear, 1, char_to_terminal);

	return selected;
}

int char_to_terminal(int char_to_write){
	if(output_stream) putc(char_to_write, output_stream);
	return 0;
}
