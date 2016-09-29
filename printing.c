// Compiler Builder 8
// Lester Young
// Timothy Konzel
// Remington Howell
// Johnathan Sattler
// John Herold

// Included libraries
#include "printing.h"

void printCode(sourceCode * code, int source, int clean) {

	printSourceCode(code, source);
	printCleanCode(code, clean);

	return;
}

void printSourceCode(sourceCode * code, int source) {

	sourceCode * current = code;

	if(source == 0)
		return;

	printf("\n");
	printf("source code:\n");
	printf("------------\n");

	while(current != NULL) {
		printf("%c", current -> c);
		current = current -> next;
	}

	printf("\n");

	return;
}

void printCleanCode(sourceCode * code, int clean) {

	sourceCode * current = code;
	int comment = 0;

	if(clean == 0)
		return;

	printf("\n");
	printf("source code without comments:\n");
	printf("-----------------------------\n");

	while(current != NULL) {
		if (current -> c == '\n') {
			printf("%c", current -> c);
			current = current -> next;
			continue;
		}

		if (comment == 0 && current -> next != NULL && current -> c == '/' && current -> next -> c == '*')
			comment = 1;

		if (comment == 1 && current -> next != NULL && current -> c == '*' && current -> next -> c == '/') {
			comment = 0;
			current = current -> next;
			current = current -> next;
			printf("  ");
		}

		if (comment == 0)
			printf("%c", current -> c);
		else
			printf(" ");

		current = current -> next;
	}

	printf("\n");

	return;
}