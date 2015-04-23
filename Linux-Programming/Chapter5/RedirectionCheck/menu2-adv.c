#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

	if(!isatty(fileno(stdout))){
		fprintf(stderr, "You are not a terminal!\n");
	}

	input = fopen("/dev/tty", "r");
	output = fopen("/dev/tty", "w");

	if(!input || !output){
		fprintf(stderr, "Unable to open /dev/tty\n");
		exit(0);
	}

	do{
		choice = getChoice("Please select an action", menu, input, output);
		printf("You have chose: %c\n", choice);
	}while(choice != 'q');

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
		}while(selected == '\n');

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
