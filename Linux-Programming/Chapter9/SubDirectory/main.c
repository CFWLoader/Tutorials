#include <stdlib.h>
#include "modules/a.h"

extern void functionTwo();
extern void functionThree();

int main(){

	functionTwo();
	functionThree();
	
	exit(EXIT_SUCCESS);
}
