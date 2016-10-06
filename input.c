// Compiler Builder 8
// Lester Young
// Timothy Konzel
// Remington Howell
// Johnathan Sattler
// John Herold

// Included libraries
#include "input.h"

// handle the arguments passed into the program
sourceCode * handleInput(int argc, const char * argv[], sourceCode * code, int * s, int * c) {

	const char * fileName;
	int i, source = 0, clean = 0;

	for (i = 1; i < argc; i++)
		if (strcmp(argv[i], "--source") == 0)
			source = 1;
		else if (strcmp(argv[i], "--clean") == 0)
			clean = 1;
		else
			fileName = argv[i];

	*s = source;
	*c = clean;

	code = readFile(fileName, code);

	return code;
}

// read the input file
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
