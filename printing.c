// Compiler Builder 8
// Lester Young
// Timothy Konzel
// Remington Howell
// Johnathan Sattler
// John Herold

// Included libraries
#include "printing.h"

void printCode(sourceCode * code, int source, int clean) {

	if (source == 1)
		printSourceCode(code);

	if (clean == 1)
		printCleanCode(code);

	return;
}

void printSourceCode(sourceCode * code) {

	sourceCode * current = code;

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

void printCleanCode(sourceCode * code) {

	sourceCode * current = code;
	int comment = 0;

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
			current = current -> next -> next;
			printf("  ");
			continue;
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

void printToks(tok * toks) {
	
	tok * current = toks;
	
	
	printf("\n");
	printf("tokens:\n");
	printf("-----------------------------\n");
	
	
	while(current != NULL){
		
		if (isNumber == 1){
			printf("%d", current.number);
			printf("\t");
		}
		else{
			printf("%s", current.str);
			printf("\t");
		}
		
		if (error == 1){
			printf("Error: %s\n", current.msg);
			
		}
		else{
			printf("%d", current.id);
		}


		current = current->next
	}

	printf("\n");
	
	return; 	
	
}
