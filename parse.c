// Compiler Builder 8
// Lester Young
// Timothy Konzel
// Remington Howell
// Johnathan Sattler
// John Herold

// Included libraries
#include "parse.h"

tok * parse(tok * toks, sourceCode * code) {

	sourceCode * currentCode = code;
	tok * currentTok = NULL;

	if (currentCode == NULL)
		return toks;

	currentTok = (tok *) malloc(sizeof(tok));
	toks = currentTok;



	return toks;
}
