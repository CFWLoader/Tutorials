#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

char* menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL
};

int getChoice(char* greet, char* choices[], FILE* in, FILE* out);

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

	//Add here.
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
	//New codes' end.

	do{
		choice = getChoice("Please select an action", menu, input, output);
		printf("You have chose: %c\n", choice);
	}while(choice != 'q');

	//Another new code.
	tcsetattr(fileno(input), TCSANOW, &initial_settings);

	exit(0);
}

int getChoice(char* greet, char* choices[], FILE* in, FILE* out){

	int chosen = 0;
	int selected;
	char** option;

	do{
		//printf("Choice: %s\n", greet);
		fprintf(out, "Choice: %s\n", greet);
		option = choices;
		while(*option){
			//printf("%s\n", *option);
			fprintf(out, "%s\n", *option);
			++option;
		}

		do{
			//selected = getchar();
			selected = fgetc(in);
		}while(selected == '\n' || selected == '\r');

		option = choices;
		
		while(*option){
			if(selected == *option[0]){
				chosen = 1;
				break;
			}
			++option;
		}

		if(!chosen){
			//printf("Incorrect choice, select again\n");
			fprintf(out, "Incorrect choice, select again\n");
		}

	}while(!chosen);

	return selected;
}
