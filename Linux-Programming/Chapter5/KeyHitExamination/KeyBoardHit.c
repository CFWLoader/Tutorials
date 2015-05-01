#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <curses.h>
#include <unistd.h>

static struct termios initialSettings, newSettings;
static int peekCharacter = -1;

void initKeyboard();
void closeKeyboard();

int keyboardHit();			//Exam the hit of keyboard.
int readCharacter();

int main(){

	int ch = 0;

	initKeyboard();

	while(ch != 'q'){
		printf("looping\n");
		sleep(1);

		if(keyboardHit()){
			ch = readCharacter();
			printf("You hit %c\n", ch);
		}
	}

	closeKeyboard();
	
	exit(0);
}

void initKeyboard(){						//Setting terminal attributes.
	tcgetattr(0, &initialSettings);

	newSettings = initialSettings;

	newSettings.c_lflag &= ~ICANON;				//Setting non-standard input mode.(Means the end of input can be determined by enter.)
	newSettings.c_lflag &= ~ECHO;				//Turn off the echo.
	newSettings.c_lflag &= ~ISIG;				//Turn on the signal capture.
	newSettings.c_cc[VMIN] = 1;
	newSettings.c_cc[VTIME] = 0;				//The two statment appeared above, setting the mode to "Function read() returns when a character got".

	tcsetattr(0, TCSANOW, &newSettings);
}

void closeKeyboard(){
	tcsetattr(0, TCSANOW, &initialSettings);
}

int keyboardHit(){

	char ch;
	int nread;

	if(peekCharacter != -1){
		return 1;
	}

	newSettings.c_cc[VMIN] = 0;

	tcsetattr(0, TCSANOW, &newSettings);

	nread = read(0, &ch, 1);

	newSettings.c_cc[VMIN] = 1;				//This statemtn set MIN=0(VTIME keeps 0),setting the mode to "Function read() check the input and return when it is called.";

	tcsetattr(0, TCSANOW, &newSettings);

	if(nread == 1){
		peekCharacter = ch;
		return 1;
	}

	return 0;
}

int readCharacter(){
	char ch;

	if(peekCharacter != -1){
		ch = peekCharacter;
		peekCharacter = -1;
		return ch;
	}

	read(0, &ch, 1);
	return ch;
}
