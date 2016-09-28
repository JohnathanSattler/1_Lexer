// Compiler Builder 8
// Lester Young
// Timothy Konzel
// Remington Howell
// Johnathan Sattler
// John Herold

// Included libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"

sourceCode * handleInput(int argc, const char * argv[], sourceCode * code) {

	const char * fileName;
	int i, source = 0, clean = 0;

	for (i = 1; i < argc; i++)
		if (strcmp(argv[i], "--source") == 0)
			source = 1;
		else if (strcmp(argv[i], "--clean") == 0)
			clean = 1;
		else
			fileName = argv[i];

	code = readFile(fileName, code);

	printCode(code, source, clean);

	return code;
}

sourceCode * readFile(const char * fileName, sourceCode * code) {

	FILE * ifp;
	char temp;
	sourceCode * last = code;

	// opens file
	ifp = fopen(fileName, "r");

	// if there is no file, execute print statement and exits function
	if (ifp == NULL) {
		printf("Error: File not found\n");
		exit(0);
	}

	while(fscanf(ifp, "%c", &temp) != EOF) {
		sourceCode * current = (sourceCode *) malloc(sizeof(sourceCode));
		current -> c = temp;
		current -> next = NULL;

		if (last == NULL) {
			last = current;
			code = last;
		} else {
			last -> next = current;
			last = last -> next;
		}
	}

	// closes file
	fclose(ifp);

	return code;
}

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
