// Compiler Builder 8
// Lester Young
// Timothy Konzel
// Remington Howell
// Johnathan Sattler
// John Herold

// Included libraries
#include "lexer.h"

// main function
int main(int argc, const char * argv[]) {

	sourceCode * code = NULL;
	tok * toks = NULL;

	int * source = (int *) malloc(sizeof(int));
	int * clean = (int *) malloc(sizeof(int));

	code = handleInput(argc, argv, code, source, clean);

	printCode(code, *source, *clean);

	toks = parse(toks, code);

	return 0;
}
