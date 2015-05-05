#include <stdlib.h>
#include "a.h"

extern void functionTwo();
extern void functionThree();

int main(){

	functionTwo();
	functionThree();
	
	exit(EXIT_SUCCESS);
}
