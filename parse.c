// Compiler Builder 8
// Lester Young
// Timothy Konzel
// Remington Howell
// Johnathan Sattler
// John Herold

// Included libraries
#include "parse.h"

char * reservedWords[] = {
	"const", "var", "procedure", "call",
	"begin", "end", "if", "then", "else",
	"while", "do", "read", "write", "odd"
};

int numReservedWords = 14;

tok * parse(tok * toks, sourceCode * code) {

	sourceCode * currentCode = code;
	tok * currentTok = NULL;

	if (currentCode == NULL)
		return toks;

	

	return toks;
}