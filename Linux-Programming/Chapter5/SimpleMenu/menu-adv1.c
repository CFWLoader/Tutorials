#include <stdio.h>
#include <stdlib.h>

char* menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL
};

int getChoice(char* greet, char* choices[]);

int main(){

	int choice = 0;

	do{
		choice = getChoice("Please select an action", menu);
		printf("You have chose: %c\n", choice);
	}while(choice != 'q');

	exit(0);
}

int getChoice(char* greet, char* choices[]){

	int chosen = 0;
	int selected;
	char** option;

	do{
		printf("Choice: %s\n", greet);
		option = choices;
		while(*option){
			printf("%s\n", *option);
			++option;
		}

		do{
			selected = getchar();			//Note that here is different from originals.
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
			printf("Incorrect choice, select again\n");
		}

	}while(!chosen);

	return selected;
}
