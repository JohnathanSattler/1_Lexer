// Compiler Builder 8
// Lester Young
// Timothy Konzel
// Remington Howell
// Johnathan Sattler
// John Herold

// Included libraries
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "tokens.h"

int main(int argc, const char * argv[]) {

	sourceCode * code = NULL;
	
	handleInput(argc, argv, code);

	return 0;
}
