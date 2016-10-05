// Compiler Builder 8
// Lester Young
// Timothy Konzel
// Remington Howell
// Johnathan Sattler
// John Herold

// Included libraries
#include "parse.h"
#include "string.h"

char * reservedWords[] = {
	"const", "var", "procedure", "call",
	"begin", "end", "if", "then", "else",
	"while", "do", "read", "write", "odd"
};

int numReservedWords = 14;

char * symbols[] = {
	"+", "-", "*", "/", "=", "<>",
	"<=", "<", ">=", ">=", ":=",
	",", ";", ".", "(", ")"
};

int numSymbols = 16;

tok * parse(tok * toks, sourceCode * code) {

	sourceCode * currentCode = code;
	tok * currentTok = NULL;

	while (currentCode != NULL) {
		currentTok = malloc(sizeof(tok*));
		
		// other things need to go here i suppose
		// need: isNumber, the unions (idk how that works)
		
		currentTok->str = getNextTok(code);
		//currentTok->id = some number, i don't quite know what this is meant to be
		currentTok->next = NULL;
		
		if(strlen(currentTok->str) > 12) currentTok->error = 1;
		else currentTok->error = 0;
		
		// add the currentTok to toks->next if toks is not null
		if(toks != NULL) {
			toks->next = currentTok
		}
		// else set first tok to currentTok
		else{
			tok = currentTok;
		}
		
		currentTok = NULL;
	}

	return toks;
}

char * getNextTok(sourceCode * code) {
    if (code == NULL || code->c == NULL) { // null checking
        return code;
    }

    /*
    This is to check if the first char in token
    is a symbol or not, if it changes after
    then we know its end of a token
    */
    int isSym = 0;
    if (!isalnum(code->c))
        isSym = 1;

    char * tokenString = "";

    /*
    if its not the end of the token, keep adding
    */
    while (!isEnd(char->c, isSym, tokenString)) {
        strcat(tokenString, char->c);
        code = code->next;
    }

    return tokenString;
}

int isEnd(char c, int isSym, char * str) {
    /*
    This base case checks to see if the next char
    to be added is null, new line, white space,
    or tab, if it is any of these we have reached
    the end of a token
    */
    if (c == NULL ||c == '\n' || c == ' ' || c == '\t')
        return 1;
    /*
    This base case checks if it was a symbol and the
    next char to add is not a symbol, and vice-versa
    if either of these occur we have reached the end of a token
    */
    if ((isSym = 1 && isalnum(c)) || (isSym == 0 && !isalnum(c)))
        return 1;

    /*
    This base case is to check for duplicate symbols
    so they can be separated into different tokens
    ex: ++ )) -- etc, these would have to be in different tokens
    this covers all normal programming but what happens
    if some idiot comes along and types @$%&#@$^ in the code
        any ideas?
    */

    /*
        You should allow for duplicate symbols in the code. That way if
        you ever wanted to add something like i++ it would work. You
        can check if the symbol isn't allowed when checking for errors later on.
    */

    char lastChar;
    if (strlen(str) > 1)
        lastChar = str[(strlen(str)-1)];
    if (lastChar != NULL && strcmp(lastChar, c) && c == '+'
        && c == '-' && c == ')' && c == '(' && '<' && '>')
        return 1;
    return 0;
}

